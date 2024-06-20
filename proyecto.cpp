#include <iostream>
#include <vector>
#include <string>

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

int main() {
    // Vector de pedidos (simulando la entrada de datos)
    vector<Pedido> pedidos = {
        {1, 500.0, "buenos aires", 1000.0, "Juan Perez", "12345678"},
        {2, 300.0, "jujuy", 800.0, "Maria Lopez", "23456789"},
        {3, 700.0, "cordoba", 1500.0, "Carlos Garcia", "34567890"},
        {4, 400.0, "buenos aires", 1200.0, "Ana Torres", "45678901"},
        {5, 600.0, "salta", 2000.0, "Luis Martinez", "56789012"},
        {6, 200.0, "santiago del estero", 700.0, "Jose Fernandez", "67890123"},
        {7, 300.0, "buenos aires", 900.0, "Miguel Chavez", "78901234"}
    };

    // Determinar la provincia con más pedidos
    string provincia = provinciaConMasPedidos(pedidos);
    cout << "La provincia con más pedidos es: " << provincia << endl;

    return 0;
}
