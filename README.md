# Homework 2

## Introducción
Este repositorio contiene las soluciones para los ejercicios del **Homework 2** de la materia **I102 - Paradigmas de Programación**. Cada ejercicio se encuentra en su respectiva carpeta, y las instrucciones de compilación están detalladas a continuación.


## Ejercicio 1

## Ejercicio 2

## Ejercicio 3
 Se sobrecargaron los operadores básicos (`+`, `-`, `*`, `/`) para que se puedan usar de manera natural entre objetos, como si fueran tipos nativos. Asimismo, esta implementación permite hacer cuentas mezclando distintos tipos números. Si sumás, por ejemplo, un Entero con un Real, el sistema se encarga de convertirlos internamente para que todo funcione bien y no se pierda precisión. Este comportamiento sigue la jerarquía propia de estos conjuntos numericos (`Entero < Real < Complejo`).

Existen dos formas de compilar este ejercicio (ambos deben ejecutarse desde la carpeta de Ejercicio3):
- Una versión con una interfaz por terminal que permite probar la implementación.
- Una versión de tests en la que se ejecutan pruebas prefabricadas que prueban el funcionamiento de las clases.

**Compilar el ejercicio 3 con interfaz de usuario**
```bash
g++ -o Ejercicio3 Number/Number.cpp Integer/Integer.cpp Real/Real.cpp Complex/Complex.cpp Menu.cpp
```
> Nota: Para usar la interfaz es necesario crear primero un número de algún tipo (Opciones 1, 2 y 3) y luego al acceder a las operaciones se le pedirá el segundo número y su tipo.

**Compilar los tests del ejercicio 3**
```bash
g++ -o Ejercicio3 Number/Number.cpp Integer/Integer.cpp Real/Real.cpp Complex/Complex.cpp Tests.cpp
```

## Ejercicio 4

### **Compilación**
Para compilar el código del Ejercicio 4, usa el siguiente comando dentro de la carpeta Ejercicio4:

```bash
g++ -o Ejercicio4 Caja/Caja.cpp CuentaCorriente/CuentaCorriente.cpp Cuenta/Cuenta.cpp BancoTest.cpp
```

### Elección de Especificadores de Acceso en la Jerarquía de Cuentas Bancarias

##### Clase Cuenta (Abstracta)
Atributos: `protected` y `privated`

```cpp
protected:
    double balance;
```

El atributo balance se declaró como `protected` para que pueda ser accedido directamente desde las subclases, como `Caja` y `CuentaCorriente`. Esta decisión mejora la eficiencia y legibilidad en las subclases sin comprometer la seguridad, ya que este atributo sigue sin estar accesible desde código externo. Evitar public protege contra modificaciones directas e incontroladas desde fuera de la jerarquía.

```cpp
private:
std::string titularCuenta;
```

El atributo titularCuenta se declara como `privated` porque representa una información sensible y fija de la cuenta: el nombre del titular. No se espera que este valor cambie una vez asignado al crear la cuenta, por lo tanto, se restringe su modificación desde fuera de la clase para preservar la integridad de los datos y mantener un buen encapsulamiento.

Métodos: `public`

```cpp
public:
    Cuenta(std::string titular, double bal = 0.0);
    std::string get_titular();

    virtual void depositar(double cantidad);
    virtual void retirar(double cantidad) = 0;
    virtual void mostrarInfo() const = 0;
    virtual ~Cuenta() = default;
```

Los métodos públicos constituyen la interfaz de uso de la clase. Esto permite a los usuarios operar con objetos de tipo Cuenta sin conocer la implementación específica. Se declaran como virtuales para permitir el polimorfismo y dos de ellos (retirar y mostrarInfo) son puros, haciendo de Cuenta una clase abstracta. Esto obliga a las subclases a definir su comportamiento particular.

##### Clase CajaDeAhorro
Atributo: `private`

```cpp
private:
    int contadorVistas;
    friend class CuentaCorriente;
```

Este atributo es interno y específico de la lógica de CajaDeAhorro. No es necesario ni deseable que otras clases tengan acceso directo a él, ya que su único propósito es contar las llamadas a mostrarInfo. Declararlo como private asegura que su gestión queda encapsulada dentro de la clase y puede modificarse sin afectar a usuarios o subclases. Se declara a `CuentaCorriente` como *friend* de `CajaDeAhorro` para permitir el acceso directo a su balance al realizar retiros que exceden los fondos. Si bien sería preferible usar un método como get_balance() por razones de **encapsulamiento** y **mantenibilidad**, se optó por friend para cumplir con los requerimientos de la consigna.

Métodos: `public`

```cpp
public:
    CajaDeAhorro(std::string titular, double bal = 0.0);
    void retirar(double cantidad) override;
    void mostrarInfo() const override;
```

Se declaran public para poder instanciar objetos y acceder a su funcionalidad desde el exterior, incluyendo el uso de punteros a Cuenta que apunten a instancias de CajaDeAhorro. El modificador override asegura que se esté sobrescribiendo correctamente los métodos virtuales de la clase base.

##### Clase CuentaCorriente
Atributo: `private`

```cpp
private:
    CajaDeAhorro* respaldo;
```

Este puntero a una instancia de CajaDeAhorro representa una relación de apoyo entre cuentas. Se declara private ya que su gestión es completamente interna a la clase CuentaCorriente. No se espera que otras clases o funciones externas modifiquen directamente esta relación, lo cual previene errores.

Métodos: `public`

```cpp
public:
    CuentaCorriente(std::string titular, double bal = 0.0, CajaDeAhorro* respaldo = nullptr);
    void retirar(double cantidad) override;
    void mostrarInfo() const override;
```

Siguiendo el mismo criterio que en las otras clases, estos métodos se exponen como public para permitir la correcta interacción con el objeto desde el exterior, especialmente a través de punteros o referencias a Cuenta.