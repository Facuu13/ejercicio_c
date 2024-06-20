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


// Función para encontrar el DNI del responsable que facturó un pedido dado su código
string encontrarDniPorCodigo(const vector<Pedido>& pedidos, int codigoPedido) {
    for (const auto& pedido : pedidos) {
        if (pedido.codigo == codigoPedido) {
            return pedido.dni;
        }
    }
    return ""; // Si no se encuentra el código, devolvemos una cadena vacía
}


// Función para calcular el costo total de los pedidos que llegaron a una provincia específica
double calcularCostoTotalPorProvincia(const vector<Pedido>& pedidos, const string& provinciaBuscada) {
    double costoTotal = 0.0;

    for (const auto& pedido : pedidos) {
        if (pedido.provincia == provinciaBuscada) {
            costoTotal += pedido.costo;
        }
    }

    return costoTotal;
}


// Función para calcular el porcentaje de pedidos facturados por un responsable específico
double calcularPorcentajePedidosPorResponsable(const vector<Pedido>& pedidos, const string& nombreResponsable) {
    int totalPedidos = pedidos.size();
    int pedidosPorResponsable = 0;

    for (const auto& pedido : pedidos) {
        if (pedido.responsable == nombreResponsable) {
            pedidosPorResponsable++;
        }
    }

    if (totalPedidos == 0) {
        return 0.0; // Evitar división por cero
    }

    return (static_cast<double>(pedidosPorResponsable) / totalPedidos) * 100.0;
}

// Función void para imprimir la cantidad de pedidos con peso menor al límite especificado
void imprimirCantidadPedidosMenoresAlLimite(const vector<Pedido>& pedidos, double limitePeso) {
    int cantidadPedidos = 0;

    for (const auto& pedido : pedidos) {
        if (pedido.peso < limitePeso) {
            cantidadPedidos++;
        }
    }

    cout << "Cantidad de pedidos con peso menor a " << limitePeso << " kilos: " << cantidadPedidos << endl;
}


// Función para encontrar el código del pedido más liviano que llegó a una provincia específica
int encontrarPedidoMasLivianoEnProvincia(const vector<Pedido>& pedidos, const string& provinciaBuscada) {
    //Indicamos que todavia no se ha encontrado ningun pedido
    int codigoMasLiviano = -1;
    double pesoMasLiviano = 10000000000.0; //para asegurar que cualquier peso sea menor al inicializado.

    for (const auto& pedido : pedidos) {
        if (pedido.provincia == provinciaBuscada && pedido.peso < pesoMasLiviano) {
            pesoMasLiviano = pedido.peso;
            codigoMasLiviano = pedido.codigo;
        }
    }

    return codigoMasLiviano;
}


// Función void para calcular e imprimir el total facturado por todas las provincias
void calcularEImprimirTotalFacturado(const vector<Pedido>& pedidos) {
    double totalGeneral = 0.0;

    for (const auto& pedido : pedidos) {
        totalGeneral += pedido.costo;
    }

    cout << "Total facturado por todas las provincias: $" << totalGeneral << endl;
}


// Función para calcular el total facturado por pedidos cuyo responsable no sea el nombre especificado
double calcularTotalFacturadoPorNoResponsable(const vector<Pedido>& pedidos, const string& nombreResponsable) {
    double totalFacturado = 0.0;

    for (const auto& pedido : pedidos) {
        if (pedido.responsable != nombreResponsable) {
            totalFacturado += pedido.costo;
        }
    }

    return totalFacturado;
}

int main() {
    // Vector de pedidos (simulando la entrada de datos)
    vector<Pedido> pedidos = {
        {1, 500.0, "buenos aires", 1000.0, "Juan Perez", "12345678"},
        {2, 75.0, "jujuy", 800.0, "Maria Lopez", "23456789"},
        {12655, 700.0, "cordoba", 1500.0, "Carlos Garcia", "34567890"},
        {4, 90.0, "buenos aires", 1200.0, "Ana Torres", "45678901"},
        {5, 60.0, "salta", 2000.0, "Luis Martinez", "56789012"},
        {6, 200.0, "santiago del estero", 700.0, "Jose Fernandez", "67890123"},
        {7, 800.0, "buenos aires", 900.0, "Carlos Chavez", "78901234"},
        {8, 90.0, "catamarca", 1200.0, "Ana Torres", "45678901"},
    };

    //Ejercicio 1
    cout << "EJERCICIO 1 " << endl;
    // Determinar la provincia con más pedidos
    string provincia = provinciaConMasPedidos(pedidos);
    cout << "La provincia con más pedidos es: " << provincia << endl;
    cout << "------------------- " << endl;

    //Ejercicio 2
    cout << "EJERCICIO 2 " << endl;
    // Nombre del responsable a buscar
    string nombre = "Carlos";
    // Imprimir los pedidos facturados a nombre del responsable especificado
    cout << "Pedidos facturados a nombre de " << nombre << ":" << endl;
    imprimirPedidosPorNombre(pedidos, nombre);
    cout << "------------------- " << endl;

    //Ejercicio 3
    cout << "EJERCICIO 3 " << endl;
    // Calcular el porcentaje de pedidos cuyo peso está entre 50 y 100 kilos
    double porcentaje = calcularPorcentajePedidos(pedidos, 50.0, 100.0);
    cout << "Porcentaje de pedidos cuyo peso está entre 50 y 100 kilos: " << porcentaje << "%" << endl;
    cout << "------------------- " << endl;

    //Ejercicio 4  
    cout << "EJERCICIO 4 " << endl;
    // Encontrar el DNI del responsable que facturó el pedido más pesado
    string dniMasPesado = encontrarDniPedidoMasPesado(pedidos);
    cout << "El DNI del responsable que facturó el pedido más pesado es: " << dniMasPesado << endl;
    cout << "------------------- " << endl;

    //Ejercicio 5
    cout << "EJERCICIO 5 " << endl;
    //ingresamos el codigo 
    int codigoBuscado = 12655;
    // Encontrar el DNI del responsable que facturó el pedido buscado
    string dniResponsable = encontrarDniPorCodigo(pedidos, codigoBuscado);
    // Imprimir el resultado
    if (!dniResponsable.empty()) {
        cout << "El DNI del responsable que facturó el pedido con código " << codigoBuscado << " es: " << dniResponsable << endl;
    } else {
        cout << "No se encontró ningún pedido con código " << codigoBuscado << endl;
    }
    cout << "------------------- " << endl;

    //Ejercicio 6
    cout << "EJERCICIO 6 " << endl;
    // Calcular el costo total de los pedidos que llegaron a la provincia de Córdoba
    string provinciaBuscada = "cordoba";
    double costoTotal = calcularCostoTotalPorProvincia(pedidos, provinciaBuscada);
    // Imprimir el resultado
    cout << "Costo total de los pedidos que llegaron a la provincia de " << provinciaBuscada << ": $" << costoTotal << endl;
    cout << "------------------- " << endl;

    //Ejercicio 7
    cout << "EJERCICIO 7 " << endl;
    // Nombre del responsable buscado
    string nombreResponsable = "Raul Sanchez";
    // Calcular el porcentaje de pedidos facturados por el responsable buscado
    double porcentaje_pedido = calcularPorcentajePedidosPorResponsable(pedidos, nombreResponsable);
    // Imprimir el resultado
    cout << "Porcentaje de pedidos facturados por " << nombreResponsable << ": " << porcentaje_pedido << "%" << endl;
    cout << "------------------- " << endl;

    //Ejercicio 8 , en este ejercicio usamos la misma funcion del ejercicio 3
    cout << "EJERCICIO 8 " << endl;
    // Calcular el porcentaje de pedidos cuyo peso está entre 90 y 120 kilos
    double porcentaje_2 = calcularPorcentajePedidos(pedidos,90.0, 120.0);
    cout << "Porcentaje de pedidos cuyo peso está entre 90 y 120 kilos: " << porcentaje_2 << "%" << endl;
    cout << "------------------- " << endl;

    //Ejercicio 9
    cout << "EJERCICIO 9 " << endl;
    // Ingresamos el límite de peso para comparar
    double limitePeso = 50.0;
    // Llamamos a la función para imprimir la cantidad de pedidos con peso menor al límite especificado
    imprimirCantidadPedidosMenoresAlLimite(pedidos, limitePeso);
    cout << "------------------- " << endl;

    //Ejercicio 10
    cout << "EJERCICIO 10 " << endl;
    // Provincia buscada
    string provinciaBuscada2 = "catamarca";
    // Encontrar el código del pedido más liviano que llegó a la provincia buscada
    int codigoMasLiviano = encontrarPedidoMasLivianoEnProvincia(pedidos, provinciaBuscada2);
    if (codigoMasLiviano != -1) {
        cout << "Código del pedido más liviano que llegó a la provincia de " << provinciaBuscada2 << ": " << codigoMasLiviano << endl;
    } else {
        cout << "No se encontraron pedidos en la provincia de " << provinciaBuscada2 << endl;
    }
    cout << "------------------- " << endl;

    //Ejercicio 11 , en este ejercicio usamos la misma funcion del ejercicio 3
    cout << "EJERCICIO 11 " << endl;
    // Calcular el porcentaje de pedidos cuyo peso está entre 200 y 500 kilos
    double porcentaje_3 = calcularPorcentajePedidos(pedidos,200.0, 500.0);
    cout << "Porcentaje de pedidos cuyo peso está entre 200 y 500 kilos: " << porcentaje_3 << "%" << endl;
    cout << "------------------- " << endl;

    //Ejercicio 12 
    cout << "EJERCICIO 12 " << endl;
    // Llamamos a la función para calcular e imprimir el total facturado por todas las provincias
    calcularEImprimirTotalFacturado(pedidos);
    cout << "------------------- " << endl;

    //Ejercicio 13 
    cout << "EJERCICIO 13 " << endl;
    string nombreResponsable2 = "Juan Perez";
    // Calcular el total facturado por pedidos cuyo responsable no sea el nombre especificado
    double totalFacturado = calcularTotalFacturadoPorNoResponsable(pedidos, nombreResponsable2);
    // Imprimir el resultado
    cout << "Total facturado por pedidos cuyo responsable no es " << nombreResponsable2 << ": $" << totalFacturado << endl;
    cout << "------------------- " << endl;


    return 0;
}
