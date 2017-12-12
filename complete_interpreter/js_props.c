/*
 *	js_props -> Property access and prototype/scope traversals
 */

#include "js_props.h"

// ----------------------------------------------------------------------------
// Get a property
// ----------------------------------------------------------------------------

/* Lookup a property on an object, resolve the value, and return it. */
js_val *js_get(js_val *obj, char *name)
{
  // We can't read properties from undefined.
  if (obj->type == T_UNDEF)
    js_throw(NULL, js_new_error(E_TYPE, "Cannot read property '%s' of undefined", name));

  // But we'll happily return undefined if a property doesn't exist.
  js_prop *prop = js_get_prop(obj, name);
  return prop ? prop->ptr : JSUNDEF();
}

/* Same as `js_get`, but recurse the scope chain. */
js_val *js_get_rec(js_val *obj, char *name)
{
  js_prop *prop = js_get_prop_rec(obj, name);
  return prop ? prop->ptr : JSUNDEF();
}

/* Same as `js_get`, but recurse the prototype chain (if one exists). */
js_val *js_get_proto(js_val *obj, char *name) {
  js_prop *prop = js_get_prop_proto(obj, name);
  js_val *val = prop ? prop->ptr : JSUNDEF();
  // Store a ref to the instance for natively define methods.
  if (IS_FUNC(val)) {
    val->object.instance = obj;
  }
  return val;
}

/* Lookup a property on an object and return it. */
js_prop *js_get_prop(js_val *obj, char *name) {
  js_prop *prop = NULL;
  if (obj->map)
    HASH_FIND_STR(obj->map, name, prop);
  return prop;
}

js_prop *js_get_prop_rec(js_val *obj, char *name) {
  js_prop *prop = js_get_prop(obj, name);
  if (prop == NULL && obj->object.parent != NULL)
    return js_get_prop_rec(obj->object.parent, name);
  return prop;
}

js_prop *js_get_prop_proto(js_val *obj, char *name) {
  js_prop *prop = js_get_prop(obj, name);
  if (prop == NULL && obj->proto != NULL)
    return js_get_prop_proto(obj->proto, name);
  return prop;
}


// ----------------------------------------------------------------------------
// Set a property
// ----------------------------------------------------------------------------

/* Set a property on an object using the provided name and value, and the
 * default property flags.
 */
void js_set(js_val *obj, char *name, js_val *val) {
  js_set_prop(obj, name, val, P_IGNORE);
}

/* Set a property on an object using the provided name, value, and property
 * flags.
 */
void js_set_prop(js_val *obj, char *name, js_val *val, js_prop_flags flags) {
  // Get the existing prop or create a new one.
  bool new = false;
  js_prop *prop = js_get_prop(obj, name);
  if (prop == NULL) {
    prop = js_new_prop(P_DEFAULT);
    new = true;
  }

  // Update the prop flags.
  // The P_IGNORE value is used to convey that the flags should not be changed.
  if (flags != P_IGNORE) {
    prop->writable = flags & P_WRITE;
    prop->configurable = flags & P_CONF;
    prop->enumerable = flags & P_ENUM;
  }

  prop->ptr = val;
  prop->circular = prop->ptr == obj ? 1 : 0; // Do we have a circular reference?

  // Add the prop if new
  if (new) {
    prop->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(prop->name, name);
    prop->name[strlen(name)] = '\0';
    HASH_ADD_KEYPTR(hh, obj->map, prop->name, strlen(prop->name), prop);
  }
}

/* Set a property on the given object, or -- if not defined -- the closest
 * parent scope on which the name is already defined.
 */
void js_set_rec(js_val *obj, char *name, js_val *val)
{
  js_val *scope_to_set = obj;
  js_val *parent = NULL;

  // Try and find the property in a parent scope.
  js_prop *prop = js_get_prop(obj, name);
  while (prop == NULL) {
    if (obj->object.parent == NULL) break;
    parent = obj->object.parent;
    prop = js_get_prop(parent, name);
    obj = parent;
  }
  if (prop != NULL && parent != NULL)
    scope_to_set = parent;

  js_set(scope_to_set, name, val);
}

// ----------------------------------------------------------------------------
// Delete a property
// ----------------------------------------------------------------------------

/* Find and delete a property from an object by name. */
bool js_del_prop(js_val *obj, char *name)
{
  js_prop *deletee = js_get_prop(obj, name);
  if (!deletee) return false;
  HASH_DEL(obj->map, deletee);
  return true;
}
