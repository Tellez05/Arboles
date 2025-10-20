#include "MyBST.h"

int main() {
    MyBST arbol;

    cout << "=== PRUEBA DE FUNCIONALIDAD DE MyBST ===\n\n";

    // 🔹 Inserción de elementos
    cout << "Insertando elementos: 8, 3, 10, 1, 6, 14, 4, 7, 13\n";
    arbol.insert(8);
    arbol.insert(3);
    arbol.insert(10);
    arbol.insert(1);
    arbol.insert(6);
    arbol.insert(14);
    arbol.insert(4);
    arbol.insert(7);
    arbol.insert(13);

    // 🔹 Recorridos usando visit()
    cout << "\nPreorder (visit 1): ";
    arbol.visit(1);

    cout << "\nInorder (visit 2): ";
    arbol.visit(2);

    cout << "\nPostorder (visit 3): ";
    arbol.visit(3);

    cout << "\nLevel order (visit 4): ";
    arbol.visit(4);

    // 🔹 Búsqueda
    cout << "\n\nBuscando valores 6 y 20:\n";
    cout << "¿Existe 6? " << (arbol.search(6) ? "Sí" : "No") << endl;
    cout << "¿Existe 20? " << (arbol.search(20) ? "Sí" : "No") << endl;

    // 🔹 Altura
    cout << "\nAltura del árbol: " << arbol.height() << endl;

    // 🔹 Ancestros
    cout << "\nAncestros del nodo 7: ";
    arbol.ancestors(7);
    cout << endl;

    // 🔹 Nivel de un nodo
    cout << "\nNivel del nodo 13: " << arbol.whatLevelAmI(13) << endl;
    cout << "Nivel del nodo 20: " << arbol.whatLevelAmI(20) << endl;

    // 🔹 Eliminación
    cout << "\nEliminando nodo 10 (1 hijo): " 
         << (arbol.remove(10) ? "Eliminado" : "No encontrado") << endl;
    cout << "Eliminando nodo 3 (2 hijos): " 
         << (arbol.remove(3) ? "Eliminado" : "No encontrado") << endl;
    cout << "Eliminando nodo 1 (hoja): " 
         << (arbol.remove(1) ? "Eliminado" : "No encontrado") << endl;

    cout << "\nInorder después de eliminar: ";
    arbol.visit(2);

    cout << "\n\n=== FIN DE PRUEBAS ===" << endl;
    return 0;
}
