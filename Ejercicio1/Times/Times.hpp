#pragma once
#include <string>

class Times {
private:
    int hour;               // Hora en formato de 0 a 11
    int min;                // Minutos en formato de 0 a 59
    int sec;                // Segundos en formato de 0 a 59
    std::string tday;       // Indicador de "a.m." o "p.m."

    /// Imprime la hora interna en formato "HHh:MMm:SSs " (sin a.m./p.m.)
    void print_time() const;

    /// Verifica que los minutos o segundos estén en el rango [0, 59]
    void check_timelimit60(int x) const;

    /// Verifica que la hora esté en el rango [0, 11]
    void check_hourlimit(int h) const;

    /// Verifica que el indicador de tiempo (tday) sea válido ("a.m." o "p.m.")
    void check_timeday(const std::string& td) const;

    /// Formatea el string de a.m./p.m. al estilo correcto ("a.m."/"p.m.")
    std::string format_timeday(const std::string& td) const;

public:
    /**
     * Constructor con parámetros opcionales.
     * Permite inicializar solo la hora, o también minutos, segundos y "a.m."/"p.m."
     * Por defecto se crea el tiempo 00h:00m:00s a.m.
     */
    Times(int h = 0, int m = 0, int s = 0, std::string td = "a.m.");

    /// Devuelve la hora
    int get_hour() const;

    /// Establece una nueva hora, validando el rango [0, 11]
    void set_hour(int h);

    /// Devuelve los minutos
    int get_minute() const;

    /// Establece los minutos, validando el rango [0, 59]
    void set_minute(int m);

    /// Devuelve los segundos
    int get_sec() const;

    /// Establece los segundos, validando el rango [0, 59]
    void set_sec(int s);

    /// Devuelve "a.m." o "p.m."
    std::string get_timeday() const;

    /// Establece el indicador "a.m." o "p.m." con validación
    void set_timeday(const std::string& td);

    /// Imprime la hora en formato 12h con "a.m." o "p.m."
    void print_time12() const;

    /// Imprime la hora convertida al formato 24h
    void print_time24();
};

