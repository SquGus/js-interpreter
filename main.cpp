#include <iostream>
#include <cstdlib>
#include <cstring>

#include "js_driver.hpp"

int 
main( const int argc, const char **argv )
{
   /** check for the right # of arguments **/
   if( argc == 2 )
   {
      /** instantiate driver object **/
      JS::JS_Driver driver;
      /** example for piping input from terminal, i.e., using cat **/ 
      if( std::strncmp( argv[ 1 ], "-o", 2 ) == 0 )
      {
         driver.parse( std::cin );
      }
      /** simple help menu **/
      else if( std::strncmp( argv[ 1 ], "-h", 2 ) == 0 )
      {
         std::cout << "to get help\n\tmy_js_interpreter -h\n\n";
         std::cout << "to process input from terminal\n\tmy_js_interpreter -o <input from terminal>\n\n";
         std::cout << "to process file\n\tmy_js_interpreter <file to interpret>\n\n";
         return( EXIT_SUCCESS );
      }
      /** example reading input from a file **/
      else
      {
         /** assume file, prod code, use stat to check **/
         driver.parse( argv[1] );
      }
      //driver.print( std::cout ) << "\n";
   }
   else
   {
      /** exit with failure condition **/
      std::cout << "Error! usage:\n";
      std::cout << "to get help\n\tmy_js_interpreter -h\n\n";
      std::cout << "to process input from terminal\n\tmy_js_interpreter -o <input from terminal>\n\n";
      std::cout << "to process file\n\tmy_js_interpreter <file to interpret>\n\n";
      return ( EXIT_FAILURE );
   }
   return( EXIT_SUCCESS );
}