#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Definimos una estructura para almacenar la información de cada pedido
struct Pedido {
    int codigo;
    double peso;
    string provincia;
    double costo;
    string responsable;
    string dni;
};

// Función para determinar la provincia con más pedidos
string provinciaConMasPedidos(const vector<Pedido>& pedidos) {
    // Lista de provincias
    string provincias[] = {"buenos aires", "jujuy", "cordoba", "santiago del estero", "salta"};
    int contadorPedidos[5] = {0}; // Inicializa el contador de pedidos para cada provincia en 0

    // Contar los pedidos por provincia
    for (const auto& pedido : pedidos) {
        if (pedido.provincia == "buenos aires") contadorPedidos[0]++;
        else if (pedido.provincia == "jujuy") contadorPedidos[1]++;
        else if (pedido.provincia == "cordoba") contadorPedidos[2]++;
        else if (pedido.provincia == "santiago del estero") contadorPedidos[3]++;
        else if (pedido.provincia == "salta") contadorPedidos[4]++;
    }

    // Determinar la provincia con más pedidos
    int maxPedidos = contadorPedidos[0];
    int provinciaIndex = 0;
    for (int i = 1; i < 5; ++i) {
        if (contadorPedidos[i] > maxPedidos) {
            maxPedidos = contadorPedidos[i];
            provinciaIndex = i;
        }
    }

    return provincias[provinciaIndex];
}


// Función para imprimir los pedidos facturados a un nombre específico
void imprimirPedidosPorNombre(const vector<Pedido>& pedidos, const string& nombre) {
    for (const auto& pedido : pedidos) {
        // Verifica si el nombre del responsable contiene la subcadena especificada
        if (pedido.responsable.find(nombre) != string::npos) {
            cout << "Codigo: " << pedido.codigo << ", Peso: " << pedido.peso 
                 << ", Provincia: " << pedido.provincia << ", Costo: " << pedido.costo 
                 << ", Responsable: " << pedido.responsable << ", DNI: " << pedido.dni << endl;
        }
    }
}


// Función para calcular el porcentaje de pedidos cuyo peso está entre 50 y 100 kilos
double calcularPorcentajePedidos(const vector<Pedido>& pedidos, double pesoMin, double pesoMax) {
    int totalPedidos = pedidos.size();
    int pedidosEnRango = 0;

    for (const auto& pedido : pedidos) {
        if (pedido.peso >= pesoMin && pedido.peso <= pesoMax) {
            pedidosEnRango++;
        }
    }

    if (totalPedidos == 0) {
        return 0.0; // Evitar división por cero
    }
    //static_cast<double>(pedidosEnRango): Convierte pedidosEnRango de int a double. 
    //y asi podemos obtener el resultado sea de tipo double
    //multiplicamos por 100 para obtener el porcentaje
    return (static_cast<double>(pedidosEnRango) / totalPedidos) * 100.0; 
}


// Función para encontrar el DNI del responsable que facturó el pedido más pesado
string encontrarDniPedidoMasPesado(const vector<Pedido>& pedidos) {
    double maxPeso = 0; // Inicializamos con el menor valor posible
    string dniResponsable;

    for (const auto& pedido : pedidos) {
        if (pedido.peso > maxPeso) {
            maxPeso = pedido.peso;
            dniResponsable = pedido.dni;
        }
    }

    return dniResponsable;
}


int main() {
    // Vector de pedidos (simulando la entrada de datos)
    vector<Pedido> pedidos = {
        {1, 500.0, "buenos aires", 1000.0, "Juan Perez", "12345678"},
        {2, 75.0, "jujuy", 800.0, "Maria Lopez", "23456789"},
        {3, 700.0, "cordoba", 1500.0, "Carlos Garcia", "34567890"},
        {4, 90.0, "buenos aires", 1200.0, "Ana Torres", "45678901"},
        {5, 60.0, "salta", 2000.0, "Luis Martinez", "56789012"},
        {6, 200.0, "santiago del estero", 700.0, "Jose Fernandez", "67890123"},
        {7, 80.0, "buenos aires", 900.0, "Carlos Chavez", "78901234"}
    };

    //Ejercicio 1
    // Determinar la provincia con más pedidos
    string provincia = provinciaConMasPedidos(pedidos);
    cout << "La provincia con más pedidos es: " << provincia << endl;

    //Ejercicio 2
    // Nombre del responsable a buscar
    string nombre = "Carlos";
    // Imprimir los pedidos facturados a nombre del responsable especificado
    cout << "Pedidos facturados a nombre de " << nombre << ":" << endl;
    imprimirPedidosPorNombre(pedidos, nombre);

    //Ejercicio 3
    // Calcular el porcentaje de pedidos cuyo peso está entre 50 y 100 kilos
    double porcentaje = calcularPorcentajePedidos(pedidos, 50.0, 100.0);
    cout << "Porcentaje de pedidos cuyo peso está entre 50 y 100 kilos: " << porcentaje << "%" << endl;

    //Ejercicio 4  
    // Encontrar el DNI del responsable que facturó el pedido más pesado
    string dniMasPesado = encontrarDniPedidoMasPesado(pedidos);
    cout << "El DNI del responsable que facturó el pedido más pesado es: " << dniMasPesado << endl;

    return 0;
}
