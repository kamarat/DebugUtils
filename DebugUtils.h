#ifndef DEBUGUTILS_H
#define DEBUGUTILS_H

#include "Arduino.h"

#ifdef DEBUG

  #define DPRINT(...) Serial.print( __VA_ARGS__ )           // DPRINT is a macro, debug print
  #define DPRINTS(...) Serial.print( F( __VA_ARGS__ ))
  #define DPRINTLN(...) Serial.println( __VA_ARGS__ )       // DPRINTLN is a macro, debug print with new line
  #define DPRINTLNS(...) Serial.println( F( __VA_ARGS__ ))

  #define DPRINT2( str, ... ) Serial.print( F( str )); Serial.print( __VA_ARGS__ );
  #define DPRINTLN2( str, ... ) Serial.print( F( str )); Serial.println( __VA_ARGS__ );

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

  #if defined (__SAM3X8E__)
  #else
    int freeRAM()
    {
      int size = RAMEND;
      byte *buf;
      while ((buf = (byte *) malloc(--size)) == NULL);
      free(buf);
      return size;
    }

    #define DPRINTLN_FREERAM \
      Serial.print( F( "Free RAM : " )); \
      Serial.println( freeRAM() );
  #endif // #if defined (__SAM3X8E__)

  #define DELAY(...) delay( __VA_ARGS__ )

#else
  #define DPRINT(...)   // now defines a blank line
  #define DPRINTS(...)
  #define DPRINTLN(...)
  #define DPRINTLNS(...)
  #define DPRINT2(...)
  #define DPRINTLN2(...)
  #define DPRINTLN_POINT(...)
  #define DPRINTLN_FREERAM(...)
  #define DELAY(...)

#endif  // #ifdef DEBUG

#endif  // #ifndef DEBUGUTILS_H
