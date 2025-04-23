#include <dht_nonblocking.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11
// DHT_SENSOR_TYPE es una constante definida en la librería dht_nonblocking
// que se utiliza para definir el tipo de sensor DHT
// En este caso, se define como DHT_TYPE_11 para el sensor DHT11
// La librería dht_nonblocking es una librería de Arduino
// que permite leer sensores DHT de forma no bloqueante

static const int DHT_PIN = 2;
// Pin de datos del sensor DHT11

DHT_nonblocking dht_sensor( DHT_PIN, DHT_SENSOR_TYPE );
// Instancia del sensor DHT11
// DHT_nonblocking es una función de la librería dht_nonblocking

void setup( )
{
  Serial.begin( 9600);
  // Inicializa el puerto serie a 9600 baudios para la comunicación
  // con el monitor serie
}

static bool medir_entorno( float *temperatura, float *humedad ) {
  static unsigned long marca_tiempo = millis( );
  if( millis( ) - marca_tiempo > 3000ul ) {
    if( dht_sensor.measure( temperatura, humedad ) == true ) {
      marca_tiempo = millis( );
      return( true );
    }
	// Si no hay medida disponible, se devuelve falso
	// y no se actualiza la marca de tiempo
	// Esto evita que se llame a la función de medida
	// si no hay datos disponibles
	// Para ello, se utiliza la función millis( ) para
	// obtener el tiempo actual en milisegundos
	// y se compara con el tiempo de la última medida
	// Si ha pasado más de 3 segundos desde la última medida
	// se llama a la función de medida}
  }
  return( false );
}

void loop( ) {
  float temperatura;
  float humedad;

  // Medimos la temperatura y la humedad. Si la función devuelve
  // verdadero, entonces hay una medida disponible.
  // Si la función devuelve falso, entonces no hay medida disponible.
  // En este caso, no se hace nada.
  if( medir_entorno( &temperatura, &humedad ) == true )
  {
    Serial.print( "T = " );
    Serial.print( temperatura, 1 );
    Serial.print( " deg. C, H = " );
    Serial.print( humedad, 1 );
    Serial.println( "%" );
  }
}