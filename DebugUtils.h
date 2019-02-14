#ifndef DEBUGUTILS_H
#define DEBUGUTILS_H

#include "Arduino.h"

#ifdef DEBUG
  #define DWRITE(...) Serial.write( __VA_ARGS__ )
  #define DPRINT(...) Serial.print( __VA_ARGS__ )           // DPRINT is a macro, debug print
  #define DPRINTLN(...) Serial.println( __VA_ARGS__ )       // DPRINTLN is a macro, debug print with new line
  #define DPRINTS(...) Serial.print( F( __VA_ARGS__ ))
  #define DPRINTSLN(...) Serial.println( F( __VA_ARGS__ ))
  #define DPRINTV(...) Serial.print( F( #__VA_ARGS__ " : " )); DPRINT( __VA_ARGS__ )
  #define DPRINTVLN(...) Serial.print( F( #__VA_ARGS__ " : " )); DPRINTLN( __VA_ARGS__ )
  #define DPRINT2( str, ... ) Serial.print( F( str )); Serial.print( __VA_ARGS__ );
  #define DPRINT2LN( str, ... ) Serial.print( F( str )); Serial.println( __VA_ARGS__ );

  #define DPRINTLN_POINT( str ) \
    Serial.print( F( str )); \
    Serial.print( millis() ); \
    Serial.print( F( ": " )); \
    Serial.print( __PRETTY_FUNCTION__ ); \
    Serial.print( ' ' ); \
    Serial.print( __FILE__ ); \
    Serial.print( ':' ); \
    Serial.println( __LINE__ );
    //Serial.print( ' ' );

  //#if defined (__SAM3X8E__)
  //#else
    extern int freeRAM();

    #define DPRINTLN_FREERAM \
      Serial.print( F( "Free RAM : " )); \
      Serial.println( freeRAM() );
  //#endif // #if defined (__SAM3X8E__)

  #define DELAY(...) delay( __VA_ARGS__ )

#else  // #ifdef DEBUG
  #define DWRITE(...)
  #define DPRINT(...)   // now defines a blank line
  #define DPRINTLN(...)
  #define DPRINTS(...)
  #define DPRINTSLN(...)
  #define DPRINTV(...)
  #define DPRINTVLN(...)
  #define DPRINT2(...)
  #define DPRINT2LN(...)
  #define DPRINTLN_POINT(...)
  #define DPRINTLN_FREERAM(...)
  #define DELAY(...)
#endif  // #ifdef DEBUG

#endif  // #ifndef DEBUGUTILS_H
