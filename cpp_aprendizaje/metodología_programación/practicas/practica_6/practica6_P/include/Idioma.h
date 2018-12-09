
/**
 * @file Idioma.h
 * @author DECSAI
*/

#ifndef IDIOMA_H
#define IDIOMA_H

#include "Bigrama.h"

using namespace std;

/**
 * @class Idioma
 * @brief Representa el conjunto los bigramas asociados a un idioma junto con el
 * identificador del idioma
 */
class Idioma {
public:

    /**
     * @brief Constructor base
     */
    Idioma();

    /**
     * @brief Constructor para pre-reservar memoria
     * @param nbg Número de bigramas pre-reservados
     */
    Idioma(int nbg);

    /**
     * @brief Constructor de copia
     * @param orig El idioma que se quiere copiar
     */
    Idioma(const Idioma& orig);

    /**
     * @brief Destructor
     */
    ~Idioma();

    /**
     * @brief Sobrecarga del operador de asignación
     * @param orig Parámetro rhs de la asignación
     * @return this para concatenación de asignaciones de derecha a izquierda
     */
    Idioma& operator=(const Idioma& orig);

    /**
     * @brief Consulta el ID del idioma
     * @return ID del idioma
     */
    string getIdioma() const;

    /**
     * @brief Establece el ID del idioma
     * @param id Nuevo ID del idioma
     */
    void setIdioma(const string& id);

    /**
     * @brief Consulta la lista de bigramas
     * @param p La posición de la lista que se quiere consultar
     * @precond La posición @p p es correcta
     * @return El bigrama que ocupa la posición @p p
     */
    Bigrama getPosicion(int p) const;

    /**
     * @brief Añade un nuevo bigrama
     * @param p La posición en la que se quiere insertar el bigrama
     * @precond La posición @p p es correcta
     * @param bg El bigrama a insertar
     */
    void setPosicion(int p, const Bigrama & bg);

    /**
     * @brief Consulta el número de bigramas existentes.
     * @return El tamaño de la lista de bigramas
     */
    inline int getSize() const { return _nBigramas; };

    /**
     * @brief Busca un bigrama en la lista de bigramas
     * @param bg El bigrama que se está buscando
     * @return La posición que ocupa @p bg en la lista, -1 si no está en la lista
     */
    int findBigrama(const string& bg) const;

    /**
     * @brief Calcula la distancia entre dos idiomas
     * @param otro El segundo idioma para consultar la distancia
     * @return
     */
    double distancia(const Idioma& otro) const;

    /**
     * @brief Ordena la lista de bigramas de mayor a menor frecuencia
     */
    void ordenar();

    friend ostream & operator<<(ostream & os, const Idioma & i);
    friend istream & operator>>(istream & os, Idioma & i);

    /**
     * @brief Serializa y guarda un idioma en un fichero
     * @param fichero El fichero de salida
     * @return @b false si ha habido algún tipo de error, @b true en otro caso
     */
    bool salvarAFichero(const char *fichero) const;

    /**
     * @brief Recupera una serialización de un idioma desde un fichero y
     * reconstruye el idioma
     * @param fichero Fichero que contiene un idioma serializado
     * @return @b false si ha habido algún tipo de error, @b true en otro caso
     */
    bool cargarDeFichero(const char *fichero);
private:
    string _idioma;    /// Identificador del idioma
    Bigrama* _conjunto;     /// Vector dinámico de bigramas
    int _nBigramas;         /// Número de bigramas en el vector dinámico

    void reservarMemoria(int n);
    void liberarMemoria();
    void copiar(const Idioma& otro);


};

/**
 * @brief Serialización de un idioma para su inserción en un flujo de salida
 * @param os Flujo de salida
 * @param i Idioma a serializar
 * @return El mismo flujo de salida para inserciones consecutivas
 */
ostream & operator<<(ostream & os, const Idioma & i);

/**
 * @brief Reconstruye un Idioma a partir de una serialización
 * @param is Flujo de entrada desde el que se extrae la serialización
 * @param i Idioma reconstruido
 * @return El mismo flujo de entrada para extracciones consecutivas
 */
istream & operator>>(istream & is, Idioma & i);


#endif
