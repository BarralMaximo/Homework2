#pragma once
#include <string>

/**
 * @class Times
 * @brief Representa una hora del día en formato de 12 horas con indicador "a.m." o "p.m."
 * 
 * Esta clase permite manipular y validar horas, minutos y segundos, con funcionalidad para
 * mostrar la hora tanto en formato de 12 como de 24 horas. Incluye métodos de validación
 * y formateo, y está diseñada con parámetros por defecto para facilitar su uso.
 */
class Times {
private:
    int hour;               ///< Hora en formato [0, 11]
    int min;                ///< Minutos en formato [0, 59]
    int sec;                ///< Segundos en formato [0, 59]
    std::string tday;       ///< Indicador "a.m." o "p.m."

    /**
     * @brief Imprime la hora en formato "HHh:MMm:SSs" (sin "a.m."/"p.m.")
     */
    void print_time() const;

    /**
     * @brief Verifica que los valores de minutos o segundos estén en el rango [0, 59].
     * @param x Valor a verificar.
     */
    void check_timelimit60(int x) const;

    /**
     * @brief Verifica que el valor de hora esté en el rango [0, 11].
     * @param h Valor de hora a verificar.
     */
    void check_hourlimit(int h) const;

    /**
     * @brief Verifica que el string "a.m." o "p.m." sea válido.
     * @param td Texto a verificar.
     */
    void check_timeday(const std::string& td) const;

    /**
     * @brief Formatea el string ingresado a "a.m." o "p.m." correctamente.
     * @param td Texto a formatear.
     * @return "a.m." o "p.m." en formato válido.
     */
    std::string format_timeday(const std::string& td) const;

public:
    /**
     * @brief Constructor con parámetros opcionales.
     * 
     * Permite crear una instancia de `Times` indicando solo la hora,
     * o también minutos, segundos y el período del día ("a.m."/"p.m.").
     * 
     * @param h Hora (0 a 11)
     * @param m Minutos (0 a 59)
     * @param s Segundos (0 a 59)
     * @param td Indicador de tiempo ("a.m." o "p.m.")
     */
    Times(int h = 0, int m = 0, int s = 0, std::string td = "a.m.");

    /**
     * @brief Devuelve la hora.
     * @return Valor de la hora [0, 11].
     */
    int get_hour() const;

    /**
     * @brief Establece una nueva hora.
     * @param h Nueva hora (validada entre 0 y 11).
     */
    void set_hour(int h);

    /**
     * @brief Devuelve los minutos.
     * @return Valor de minutos [0, 59].
     */
    int get_minute() const;

    /**
     * @brief Establece los minutos.
     * @param m Valor de minutos (validado entre 0 y 59).
     */
    void set_minute(int m);

    /**
     * @brief Devuelve los segundos.
     * @return Valor de segundos [0, 59].
     */
    int get_sec() const;

    /**
     * @brief Establece los segundos.
     * @param s Valor de segundos (validado entre 0 y 59).
     */
    void set_sec(int s);

    /**
     * @brief Devuelve el indicador "a.m." o "p.m."
     * @return String con el valor de tday.
     */
    std::string get_timeday() const;

    /**
     * @brief Establece el indicador "a.m." o "p.m." con validación.
     * @param td Nuevo indicador.
     */
    void set_timeday(const std::string& td);

    /**
     * @brief Imprime la hora en formato de 12 horas con "a.m." o "p.m."
     */
    void print_time12() const;

    /**
     * @brief Imprime la hora convertida a formato de 24 horas.
     */
    void print_time24();
};