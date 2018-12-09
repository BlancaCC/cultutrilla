/**
 * @file ContadorBigramas.h
 * @author DECSAI
*/
#ifndef CONTADOR_BIGRAMAS_H
#define CONTADOR_BIGRAMAS_H

#include "Idioma.h"

class ContadorBigramas {
public:
	 /**
	  * @brief Constructor base. Es imprescindible pasar la cadena de caracteres válidos para poder dimensionar la matriz 2D
	  * @param caracteresValidos Cadena que contiene los únicos caracteres que serán considerados para contabilizar bigramas
	  */
    ContadorBigramas(const std::string& caracteresValidos);

	 /**
	  * @brief Constructor de copia
	  * @param orig El objeto que se copia en en el constructor
	  */
    ContadorBigramas(const ContadorBigramas & orig);//se puede acceder a la parte privada de orig con orig.

	 /**
	  * @brief Destructor de la clase
	  */
    ~ContadorBigramas();

	 /**
	  * @brief Devuelve el número de filas de la matriz 2D, que debe coincidir con la longitud de la cadena de caracteres válidos
	  * @return El número de filas de la matriz
	  */
    int getSize() const;

	 /**
	  * @brief Devuelve el número de bigramas en la matriz 2D cuya frecuencia es > 0
	  * @return Idem
	  */
    int getBigramasActivos() const;

	 /**
	  * @brief Añade un nuevo bigrama al contador de bigramas. Si se especifica una frecuencia, se debe sumar ésta, en otro caso, se incrementará en uno el valor de la frecuencia.
	  * @param cadena Texto del bigrama
	  * @param frecuencia (Opcional) Frecuencia del bigrama, en caso de que no se indique en la llamada, su valor por defecto será 0
	  * @return @retval true si ha tenido éxito @retval false en otro caso
	  */
    bool addBigrama(const char cadena[], int frecuencia=0);

	 /**
	  * @brief Sobrecarga del operador de asignación
	  */
    ContadorBigramas& operator=(const ContadorBigramas& orig);

	 /**
	  * @brief Sobrecarga del operador de incremento
	  */
    ContadorBigramas& operator+=(const ContadorBigramas& rhs);

	 /**
	  * @brief Carga las secuencias de texto de un fichero de texto, identifica los bigramas y calcula sus frecuencias, según lo indicado en el enunciado de la práctica
	  * @param nfichero Nombre del fichero .txt que contiene el texto a cargar
	  * @return @retval true si se ha cargado con éxito @retval false en otro caso
	  */
    bool calcularFrecuenciasBigramas(const char* nfichero);

	 /**
	  * @brief Traduce un contador de bigramas a un objeto de la clase Idioma. Para ello, el objeto Idioma deberá contener sólo los bigramas cuya frecuencia sea mayor que 0.
	  * @return El objeto de la clase Idioma que se ha construido
	  */
    Idioma toIdioma() const;

	 /**
	  * @brief Construye una matriz 2D con los respectivos contadores de bigramas a partir de un objeto de la clase Idioma, según lo indicado en el enunciado de la práctica.
	  * En cierto sentido se puede decir que "se importa el objeto Idioma en la clase ContadorBigrama".
	  * @param i El objeto de la clase Idioma que se quiere importar en la clase ContadorBigrama
	  */
    void fromIdioma(const Idioma &i);
private:
    int** _bigramas;
    std::string _caracteresValidos;

    /**
	  * @brief Reserva la memoria dinámica necesaria para una matriz2D de @a n x @a n
	  * @param n Número de filas y columnas de la matriz2D (es una matriz cuadrada)
	  */
	 void reservarMemoria(int n);

	 /**
	  * @brief Libera la memoria dinámica reservada para la matriz2D
	  */
    void liberarMemoria();

	 /**
	  * @brief Duplica el objeto que se pasa por parámetro en el objeto actual
	  * @param otro El objeto que se quiere copiar
	  */
    void copiar(const ContadorBigramas & otro);
};

#endif
