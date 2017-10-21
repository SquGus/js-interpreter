// Comment
// This is one line comment
/* This is a block comment */
var i = 10;
const size = 100;
var string1 = 'This must be a string';
var string2 = "This is also a string";

var falseBoolean = false;
var trueBoolean = true;
var undefinedVar = undefined;
var nullVar = null;
var float = 10.0;
var int = 100;
var string = 'This is also a string\n';

for (var j = 1; j <= 100; j++) {
	if (j%2 == 0) {
		console.log(j);
	} else if (j === 3) {
		console.log('j == 3');
	} else {
		console.log('This prints if j != 3 || j != even.');
	}
}