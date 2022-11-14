cmake_minimum_required(VERSION 3.23)
project(CLASE_ESTRUCTURA_DE_DATOS)

set(CMAKE_CXX_STANDARD 14)

include_directories("ACT 1.1 - RECURSION")
include_directories("ACT 1.3.1 - ALGORITMOS_BUSQUEDA")
include_directories("Act Integradora 2")
include_directories("Act Integradora 2/PROBAR_RELPIT")
include_directories("Act Integradora 2/PROBAR_VSCODE")
include_directories(ACT_INTEGRADORA3)
include_directories("ACTIVIDAD INTEGRADORA 1")
include_directories(ArbolesBinarios)
include_directories(ArreglosYApuntadores)
include_directories("CLASE 2 - ALGORITMOS_BUSQUEDA")
include_directories(GRAFOS1)
include_directories(INTEGRADORA3)
include_directories("INTEGRADORA3 - copia")
include_directories(LinkedLists)
include_directories("TAREA 1 - REPASO POO")

add_executable(CLASE_ESTRUCTURA_DE_DATOS
        "ACT 1.1 - RECURSION/Fraction.cpp"
        "ACT 1.1 - RECURSION/fraction.h"
        "ACT 1.1 - RECURSION/main.cpp"
        "ACT 1.3.1 - ALGORITMOS_BUSQUEDA/main.cpp"
        "ACT 1.3.1 - ALGORITMOS_BUSQUEDA/searcher.cpp"
        "ACT 1.3.1 - ALGORITMOS_BUSQUEDA/searcher.h"
        "Act Integradora 2/PROBAR_RELPIT/Binnacle.cpp"
        "Act Integradora 2/PROBAR_RELPIT/binnacle.h"
        "Act Integradora 2/PROBAR_RELPIT/Date.cpp"
        "Act Integradora 2/PROBAR_RELPIT/date.h"
        "Act Integradora 2/PROBAR_RELPIT/LinkedListTwo.cpp"
        "Act Integradora 2/PROBAR_RELPIT/linkedListTwo.h"
        "Act Integradora 2/PROBAR_RELPIT/main.cpp"
        "Act Integradora 2/PROBAR_RELPIT/Node.cpp"
        "Act Integradora 2/PROBAR_RELPIT/node.h"
        "Act Integradora 2/PROBAR_RELPIT/NodePtrTwo.cpp"
        "Act Integradora 2/PROBAR_RELPIT/nodePtrTwo.h"
        "Act Integradora 2/PROBAR_RELPIT/Queue.cpp"
        "Act Integradora 2/PROBAR_RELPIT/queue.h"
        "Act Integradora 2/PROBAR_VSCODE/Binnacle.cpp"
        "Act Integradora 2/PROBAR_VSCODE/binnacle.h"
        "Act Integradora 2/PROBAR_VSCODE/Date.cpp"
        "Act Integradora 2/PROBAR_VSCODE/date.h"
        "Act Integradora 2/PROBAR_VSCODE/LinkedListTwo.cpp"
        "Act Integradora 2/PROBAR_VSCODE/linkedListTwo.h"
        "Act Integradora 2/PROBAR_VSCODE/main.cpp"
        "Act Integradora 2/PROBAR_VSCODE/Node.cpp"
        "Act Integradora 2/PROBAR_VSCODE/node.h"
        "Act Integradora 2/PROBAR_VSCODE/NodePtrTwo.cpp"
        "Act Integradora 2/PROBAR_VSCODE/nodePtrTwo.h"
        "Act Integradora 2/PROBAR_VSCODE/Queue.cpp"
        "Act Integradora 2/PROBAR_VSCODE/queue.h"
        "Act Integradora 2/LinkedListTwo.cpp"
        "Act Integradora 2/linkedListTwo.h"
        "Act Integradora 2/main.cpp"
        "Act Integradora 2/Node.cpp"
        "Act Integradora 2/node.h"
        "Act Integradora 2/NodePtrTwo.cpp"
        "Act Integradora 2/nodePtrTwo.h"
        "Act Integradora 2/Queue.cpp"
        "Act Integradora 2/queue.h"
        ACT-131-FINAL/mainFinal.cpp
        ACT-131-FINAL/tempCodeRunnerFile.cpp
        ACT_INTEGRADORA3/BinarySearchTree.cpp
        ACT_INTEGRADORA3/binarySearchTree.h
        ACT_INTEGRADORA3/Binnacle.cpp
        ACT_INTEGRADORA3/binnacle.h
        ACT_INTEGRADORA3/main.cpp
        ACT_INTEGRADORA3/Node.cpp
        ACT_INTEGRADORA3/node.h
        ACT_INTEGRADORA3/NodePtr.cpp
        ACT_INTEGRADORA3/nodePtr.h
        "ACTIVIDAD INTEGRADORA 1/Bitacora.cpp"
        "ACTIVIDAD INTEGRADORA 1/bitacora.h"
        "ACTIVIDAD INTEGRADORA 1/Fecha.cpp"
        "ACTIVIDAD INTEGRADORA 1/fecha.h"
        "ACTIVIDAD INTEGRADORA 1/main.cpp"
        "ACTIVIDAD INTEGRADORA 1/tempCodeRunnerFile.cpp"
        ArbolesBinarios/BinarySearchTree.cpp
        ArbolesBinarios/binarySearchTree.h
        ArbolesBinarios/main.cpp
        ArbolesBinarios/Node.cpp
        ArbolesBinarios/node.h
        ArbolesBinarios/NodePtr.cpp
        ArbolesBinarios/nodePtr.h
        ArreglosYApuntadores/main.cpp
        ArreglosYApuntadores/Node.cpp
        ArreglosYApuntadores/node.h
        ArreglosYApuntadores/NodePtr.cpp
        ArreglosYApuntadores/nodePtr.h
        "CLASE 1 - RECURSI�N/main.cpp"
        "CLASE 2 - ALGORITMOS_BUSQUEDA/Alumno.cpp"
        "CLASE 2 - ALGORITMOS_BUSQUEDA/Alumno.h"
        "CLASE 2 - ALGORITMOS_BUSQUEDA/main.cpp"
        "CLASE 2 - ALGORITMOS_BUSQUEDA/otherMain.cpp"
        "CLASE 2 - ALGORITMOS_BUSQUEDA/sort.cpp"
        "CLASE 2 - ALGORITMOS_BUSQUEDA/tempCodeRunnerFile.cpp"
        GRAFOS1/Graph.cpp
        GRAFOS1/Graph.h
        GRAFOS1/main.cpp
        INTEGRADORA3/AVL.cpp
        INTEGRADORA3/AVL.h
        INTEGRADORA3/Binnacle.cpp
        INTEGRADORA3/Binnacle.h
        INTEGRADORA3/BST.cpp
        INTEGRADORA3/BST.h
        INTEGRADORA3/main.cpp
        INTEGRADORA3/Node.cpp
        INTEGRADORA3/Node.h
        INTEGRADORA3/NodeAVL.cpp
        INTEGRADORA3/NodeAVL.h
        INTEGRADORA3/NodePtr.cpp
        INTEGRADORA3/NodePtr.h
        "INTEGRADORA3 - copia/AVL.cpp"
        "INTEGRADORA3 - copia/AVL.h"
        "INTEGRADORA3 - copia/Binnacle.cpp"
        "INTEGRADORA3 - copia/Binnacle.h"
        "INTEGRADORA3 - copia/BST.cpp"
        "INTEGRADORA3 - copia/BST.h"
        "INTEGRADORA3 - copia/main.cpp"
        "INTEGRADORA3 - copia/Node.cpp"
        "INTEGRADORA3 - copia/Node.h"
        "INTEGRADORA3 - copia/NodeAVL.cpp"
        "INTEGRADORA3 - copia/NodeAVL.h"
        "INTEGRADORA3 - copia/NodePtr.cpp"
        "INTEGRADORA3 - copia/NodePtr.h"
        LinkedLists/LinkedList.cpp
        LinkedLists/linkedList.h
        LinkedLists/LinkedListTwo.cpp
        LinkedLists/linkedListTwo.h
        LinkedLists/main.cpp
        LinkedLists/Node.cpp
        LinkedLists/node.h
        LinkedLists/NodePtr.cpp
        LinkedLists/nodePtr.h
        LinkedLists/NodePtrTwo.cpp
        LinkedLists/nodePtrTwo.h
        LinkedLists/Queue.cpp
        LinkedLists/queue.h
        LinkedLists/Stack.cpp
        LinkedLists/stack.h
        "TAREA 1 - REPASO POO/Board.cpp"
        "TAREA 1 - REPASO POO/Board.h"
        "TAREA 1 - REPASO POO/Dice.cpp"
        "TAREA 1 - REPASO POO/Dice.h"
        "TAREA 1 - REPASO POO/main.cpp"
        "TAREA 1 - REPASO POO/MyGame.cpp"
        "TAREA 1 - REPASO POO/MyGame.h"
        "TAREA 1 - REPASO POO/Player.cpp"
        "TAREA 1 - REPASO POO/Player.h"
        "TAREA 1 - REPASO POO/Tile.cpp"
        "TAREA 1 - REPASO POO/Tile.h"
        "TAREA 1 - REPASO POO/validation.cpp"
        "TAREA 1 - REPASO POO/validation.h" Integradora-Grafos/Graph.cpp Integradora-Grafos/Graph.h Integradora-Grafos/main.cpp)
