#include "Times/Times.hpp"
#include <iostream>

using namespace std;

void menu_interactivo() {
    Times t;
    int opcion;

    while (true) {
        cout << "\n=== MENÚ DE PRUEBAS ===\n";
        cout << "1. Crear nuevo objeto Times\n";
        cout << "2. Cambiar hora\n";
        cout << "3. Cambiar minutos\n";
        cout << "4. Cambiar segundos\n";
        cout << "5. Cambiar a.m./p.m.\n";
        cout << "6. Mostrar tiempo en formato 12h\n";
        cout << "7. Mostrar tiempo en formato 24h\n";
        cout << "8. Ejecutar pruebas prefabricadas\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        try {
            if (opcion == 0) break;

            int h, m, s;
            string td;

            switch (opcion) {
                case 1: {
                    int modo;
                    cout << "\nElegí una forma de crear el objeto Times:\n";
                    cout << " 1. Sin parámetros\n";
                    cout << " 2. Solo hora\n";
                    cout << " 3. Hora y minutos\n";
                    cout << " 4. Hora, minutos y segundos\n";
                    cout << " 5. Hora, minutos, segundos y a.m./p.m.\n";
                    cout << "Opción: ";
                    cin >> modo;
                
                    int h = 0, m = 0, s = 0;
                    string td = "a.m.";
                
                    try {
                        if (modo == 1) {
                            t = Times();
                        } else if (modo == 2) {
                            cout << "Hora (0-11): "; cin >> h;
                            t = Times(h);
                        } else if (modo == 3) {
                            cout << "Hora (0-11): "; cin >> h;
                            cout << "Minutos (0-59): "; cin >> m;
                            t = Times(h, m);
                        } else if (modo == 4) {
                            cout << "Hora (0-11): "; cin >> h;
                            cout << "Minutos (0-59): "; cin >> m;
                            cout << "Segundos (0-59): "; cin >> s;
                            t = Times(h, m, s);
                        } else if (modo == 5) {
                            cout << "Hora (0-11): "; cin >> h;
                            cout << "Minutos (0-59): "; cin >> m;
                            cout << "Segundos (0-59): "; cin >> s;
                            cout << "a.m. o p.m.: "; cin >> td;
                            t = Times(h, m, s, td);
                        } else {
                            cout << "Opción inválida.\n";
                        }
                    } catch (exception& e) {
                        cout << "Error al crear el objeto Times: " << e.what() << endl;
                    }
                
                    break;
                }
                
                case 2:
                    cout << "Nueva hora (0-11): ";
                    cin >> h;
                    t.set_hour(h);
                    break;
                case 3:
                    cout << "Nuevos minutos (0-59): ";
                    cin >> m;
                    t.set_minute(m);
                    break;
                case 4:
                    cout << "Nuevos segundos (0-59): ";
                    cin >> s;
                    t.set_sec(s);
                    break;
                case 5:
                    cout << "Nuevo valor (a.m. o p.m.): ";
                    cin >> td;
                    t.set_timeday(td);
                    break;
                case 6:
                    t.print_time12();
                    break;
                case 7:
                    t.print_time24();
                    break;
                case 8: {
                    cout << "\n--- PRUEBAS PREFABRICADAS ---\n";
                
                    cout << "\n[Prueba 1] Constructor sin parámetros (debe ser 00h:00m:00s a.m.):\n";
                    Times t1;
                    t1.print_time12();
                    t1.print_time24();
                
                    cout << "\n[Prueba 2] Constructor con hora (3 a.m.):\n";
                    Times t2(3);
                    t2.print_time12();
                    t2.print_time24();
                
                    cout << "\n[Prueba 3] Constructor con hora y minutos (08:45 a.m.):\n";
                    Times t3(8, 45);
                    t3.print_time12();
                    t3.print_time24();
                
                    cout << "\n[Prueba 4] Constructor con hora, minutos y segundos (11:59:59 a.m.):\n";
                    Times t4(11, 59, 59);
                    t4.print_time12();
                    t4.print_time24();
                
                    cout << "\n[Prueba 5] Constructor completo con 'p.m.' (01:20:30 p.m.):\n";
                    Times t5(1, 20, 30, "p.m.");
                    t5.print_time12();
                    t5.print_time24();
                
                    cout << "\n[Prueba 6] Intento de constructor con parámetros inválidos (hora = 13):\n";
                    try {
                        Times t6(13, 0, 0, "a.m."); // Esto debe lanzar una excepción
                    } catch (const exception& e) {
                        cout << "Excepción capturada correctamente: " << e.what() << "\n";
                    }
                
                    cout << "\n[Prueba 7] Cambios individuales con setters (t5):\n";
                    t5.set_hour(10);
                    t5.set_minute(15);
                    t5.set_sec(45);
                    t5.set_timeday("a.m.");
                    t5.print_time12();
                    t5.print_time24();
                
                    break;
                }                    
                default:
                    cout << "Opción inválida.\n";
            }
        } catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    cout << "Saliendo del programa.\n";
}

int main() {
    menu_interactivo();
    return 0;
}
