
/////Este archivo contiene las practicas hechas en clase con el profesor.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;


void vectorsPart1();
void vectorReserve();
void iterators();
void practicaguessmyword();
void iterInventory();
void solucionguessmyword();
void ahorcado();
void swap();
void inventoryDisplay();
void MatrixBox();

//References
void badSwap(int x, int y);
void goodSwap(int& x, int& y);
void display(const vector<string>& vec);


int main()

{


    char player1; //OJO - ESTE ES CHAR PORQUE LOS VALORES DE MI MATRIZ EST�N EN COMILLAS, NO SON NUMEROS
    char player2; //OJO - ESTE ES CHAR PORQUE LOS VALORES DE MI MATRIZ EST�N EN COMILLAS, NO SON NUMEROS


    cout << "\n---Welcome to the Game TIC TAC TOE, let's play!---\n";
    cout << "\nPlayer 1, the value you need to enter is O";
    cout << "\nPlayer 2, the value you need to enter is X";

    cout << "\n";


    //Nota, nunca hacer VARIABLES fuera del main. Solo las CONSTANTES que no cambian, podrian definirse fuera del main.


    const int ROWS = 3;
    const int COLUMNS = 3;
    int attempts = 9;

    char board[ROWS][COLUMNS] = { {'1', '2', '3',},
                                       {'4', '5', '6',},
                                       {'7', '8', '9',} };

    cout << "\n---TIC TAC TOE---\n";
    for (int i = 0; i < ROWS; i++)
    {

        for (int j = 0; j < COLUMNS; j++)
        {
            cout << board[i][j];

        }

        cout << endl;

    }


    do {



        cout << "\nPlayer 1 Turn:";
        cout << "\nWhich space in the board you want to fill in?";
        cout << "\nChoose a number in the board\n";
        cin >> player1;


        for (int i = 0; i < ROWS; i++)
        {

            for (int j = 0; j < COLUMNS; j++)
            {
                if (board[i][j] == player1)
                {

                    board[i][j] = 'O';
                    attempts = attempts - 1;


                }

            }

        }



        cout << "\n---TIC TAC TOE---\n";
        for (int i = 0; i < ROWS; i++)
        {

            for (int j = 0; j < COLUMNS; j++)
            {
                cout << board[i][j];

            }

            cout << endl;

        }


        cout << "\nPlayer 2 Turn:";
        cout << "\nWhich space in the board you want to fill in?";
        cout << "\nChoose a number in the board\n";
        cin >> player2;


        for (int i = 0; i < ROWS; i++)
        {

            for (int j = 0; j < COLUMNS; j++)
            {
                if (board[i][j] == player2)
                {

                    board[i][j] = 'X';
                    attempts = attempts - 1;

                }

            }

        }



        cout << "\n---TIC TAC TOE---\n";
        for (int i = 0; i < ROWS; i++)
        {

            for (int j = 0; j < COLUMNS; j++)
            {
                cout << board[i][j];

            }

            cout << endl;

        }

    } while (attempts > 0);










}





void MatrixBox()

{

    const int HIGHT_WIDTH = 20;  //Constantes SIEMPRE van en mayusculas



    for (int i = 0; i < HIGHT_WIDTH; i++) //Ciclo para recorrer filas. Se mueve hacia abajo
    {

        for (int j = 0; j < HIGHT_WIDTH; j++) //Ciclo para recorrer Columnas. Se mueve a la derecha
        {

            int sumij = i + j;

            if (i == 0 || j == 0 || i == HIGHT_WIDTH - 1 || j == HIGHT_WIDTH - 1 || i == j || sumij == HIGHT_WIDTH - 1)

                cout << " 1 ";

            else

                cout << " . ";

        }


        cout << "\n"; // para imprimir el salto de linea despues de las recorridas en el for 

    }



}



void inventoryDisplay()
//EJERCICIO PARA IMPRIMIR VALORES DE UN VECTOR DESDE UNA FUNCION 
{

    vector<string>inventory;

    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("gun");

    display(inventory);

}


void display(const vector<string>& vec) //const se usa para que no modifique nada. Solo quiero que entre como Referencia
{

    vector<string>::const_iterator iter; //Creamos un Iterator
    for (iter = vec.begin(); iter != vec.end(); iter++)
    {

        cout << *iter << endl;
    }


}




void swap()
{
    int score1 = 20;
    int score2 = 100;


    //BAD SWAP
    badSwap(score1, score2); //Llamado a la funcion. Cuando se ejecuta, solo cambia los valores COPIA, no los originales.

    cout << score1 << endl; //Me muestra los valores sin aplicar la funcion, porque la funcion modifica LA COPIA. No los valores originales
    cout << score2 << endl; //Me muestra los valores sin aplicar la funcion, porque la funcion modifica LA COPIA. No los valores originales

    //Entonces para resolver esto, necesitamos crear una REFERENCIA, agregando "&":

    //GOOD SWAP
    goodSwap(score1, score2);

    cout << score1 << endl; //Ahora si me muestra los valores cambiados. Le puedo agregar &score1 para que me imprima el ESPACIO de memoria en lugar del valor
    cout << score2 << endl; //Ahora si me muestra los valores cambiados Le puedo agregar &score2 para que me imprima el ESPACIO de memoria en lugar del valor


}



void badSwap(int x, int y) //Funcion para hacer intercambio entre variables
{
    int aux = x; // aux = 20 Para que mantenga el valor original de x y no haya fallas de logica
    //Esta variable solo va a existir dentro de la funcion. Es local, no global.

    x = y; // x =100;
    y = aux; // y =20; 

}



void goodSwap(int& x, int& y) //Funcion para hacer intercambio entre variables
{
    int aux = x; // aux = 20 Para que mantenga el valor original de x y no haya fallas de logica
    //Esta variable solo va a existir dentro de la funcion. Es local, no global.

    x = y; // x =100;
    y = aux; // y =20; 

}



void ahorcado()
{
    //Declaracion de las variables y vectores
    vector <string> word;
    word.push_back("SEAHORSE");
    word.push_back("PALMS");
    word.push_back("SHARK");
    word.push_back("TOWEL");
    word.push_back("UMBRELLA");

    const int MAX_ATTEMPTS = 6;
    int ATTEMPTS = 0;

    int random;
    char letter;

    vector<string> USEDWORD(6);

    //Linea para seleccionar una palabra aleatoria de los valores dentro del vector
    srand(static_cast<unsigned int> (time(0)));
    random = (rand() % word.size());

    const string CHOICEWORD = word[random];
    string soFar(CHOICEWORD.size(), '_');


    //Inicio del Juego
    cout << "***Welcome to the game AHORCADO***\n" << endl;
    cout << "How To Play:" << endl;
    cout << "-I will show you blank spaces and you need to guess the word." << endl;
    cout << "-You have 6 chances to take a guess. If after 6 attempts you don't guess the correct word, you loose.\n" << endl;
    cout << "Are you ready?, Let's Play!\n" << endl;

    cout << (".____.      ") << endl;
    cout << ("|    |      ") << endl;
    cout << ("|    O      ") << endl;
    cout << ("| ---|---   ") << endl;
    cout << ("|    |      ") << endl;
    cout << ("|   | |     ") << endl;
    cout << ("|   | |     ") << endl;
    cout << ("|           ") << endl;
    cout << ("-------") << endl;
    cout << ("----------") << endl;
    cout << ("------------") << endl;

    cout << "\nDepuracion: " << endl;
    cout << CHOICEWORD << endl;

    //Interaccion con el jugador 


    do {

        //Convertir minusculas a mayusculas
        cout << "\nEnter a letter" << endl;
        cin >> letter;
        letter = toupper(letter);

        system("cls");

        if (CHOICEWORD.find(letter) != string::npos) //npos se usa para indicar que ningun valor se encontro en el string

        {
            cout << "\nYou have that right!\n";


            for (int i = 0; i < CHOICEWORD.size(); i++)

                if (CHOICEWORD[i] == letter)
                {
                    soFar[i] = letter;

                }

            cout << soFar << endl;


        }


        else
        {
            cout << "\nThat is NOT a match!\n";

            ATTEMPTS = ATTEMPTS + 1;

            cout << "\nRemaining Lifes: " << MAX_ATTEMPTS - ATTEMPTS << endl;

            if (ATTEMPTS == 1)
            {

                cout << (".____.      ") << endl;
                cout << ("|    |      ") << endl;
                cout << ("|    O      ") << endl;
                cout << ("|           ") << endl;
                cout << ("|           ") << endl;
                cout << ("|           ") << endl;
                cout << ("|           ") << endl;
                cout << ("|           ") << endl;
                cout << ("-------") << endl;
                cout << ("----------") << endl;
                cout << ("------------") << endl;

                cout << soFar << endl;
                USEDWORD[0] = letter;

                cout << "\nThe incorrect letters you have used are: " << endl;
                for (unsigned int i = 0; i < USEDWORD.size(); i++)

                {
                    cout << USEDWORD[i] << endl;
                }

            }

            if (ATTEMPTS == 2)

            {

                cout << (".____.      ") << endl;
                cout << ("|    |      ") << endl;
                cout << ("|    O      ") << endl;
                cout << ("|    |      ") << endl;
                cout << ("|    |      ") << endl;
                cout << ("|           ") << endl;
                cout << ("|           ") << endl;
                cout << ("|           ") << endl;
                cout << ("-------") << endl;
                cout << ("----------") << endl;
                cout << ("------------") << endl;

                cout << soFar << endl;
                USEDWORD[1] = letter;

                cout << "\nThe incorrect letters you have used are: " << endl;
                for (unsigned int i = 0; i < USEDWORD.size(); i++)

                {
                    cout << USEDWORD[i] << endl;
                }


            }

            if (ATTEMPTS == 3)

            {

                cout << (".____.      ") << endl;
                cout << ("|    |      ") << endl;
                cout << ("|    O      ") << endl;
                cout << ("| ---|      ") << endl;
                cout << ("|    |      ") << endl;
                cout << ("|           ") << endl;
                cout << ("|           ") << endl;
                cout << ("|           ") << endl;
                cout << ("-------") << endl;
                cout << ("----------") << endl;
                cout << ("------------") << endl;

                cout << soFar << endl;

                USEDWORD[2] = letter;

                cout << "\nThe incorrect letters you have used are: " << endl;
                for (unsigned int i = 0; i < USEDWORD.size(); i++)

                {
                    cout << USEDWORD[i] << endl;
                }
            }

            if (ATTEMPTS == 4)

            {

                cout << (".____.      ") << endl;
                cout << ("|    |      ") << endl;
                cout << ("|    O      ") << endl;
                cout << ("| ---|      ") << endl;
                cout << ("|    |      ") << endl;
                cout << ("|           ") << endl;
                cout << ("|           ") << endl;
                cout << ("|           ") << endl;
                cout << ("-------") << endl;
                cout << ("----------") << endl;
                cout << ("------------") << endl;

                cout << soFar << endl;
                USEDWORD[3] = letter;

                cout << "\nThe incorrect letters you have used are: " << endl;
                for (unsigned int i = 0; i < USEDWORD.size(); i++)

                {
                    cout << USEDWORD[i] << endl;
                }
            }



            if (ATTEMPTS == 5)

            {

                cout << (".____.      ") << endl;
                cout << ("|    |      ") << endl;
                cout << ("|    O      ") << endl;
                cout << ("| ---|---   ") << endl;
                cout << ("|    |      ") << endl;
                cout << ("|   |       ") << endl;
                cout << ("|   |       ") << endl;
                cout << ("|           ") << endl;
                cout << ("-------") << endl;
                cout << ("----------") << endl;
                cout << ("------------") << endl;

                cout << soFar << endl;
                USEDWORD[4] = letter;

                cout << "\nThe incorrect letters you have used are: " << endl;
                for (unsigned int i = 0; i < USEDWORD.size(); i++)

                {
                    cout << USEDWORD[i] << endl;
                }

            }



            if (ATTEMPTS == 6)

            {

                cout << (".____.      ") << endl;
                cout << ("|    |      ") << endl;
                cout << ("|    O      ") << endl;
                cout << ("| ---|---   ") << endl;
                cout << ("|    |      ") << endl;
                cout << ("|   | |     ") << endl;
                cout << ("|   | |     ") << endl;
                cout << ("|           ") << endl;
                cout << ("-------") << endl;
                cout << ("----------") << endl;
                cout << ("------------") << endl;

                cout << soFar << endl;
                USEDWORD[5] = letter;

                cout << "\nThe incorrect letters you have used are: " << endl;
                for (unsigned int i = 0; i < USEDWORD.size(); i++)
                {
                    cout << USEDWORD[i] << endl;
                }

            }


        }



    } while (ATTEMPTS != MAX_ATTEMPTS || soFar == CHOICEWORD);


    //Mensaje final para el jugador

    if (ATTEMPTS == MAX_ATTEMPTS)
    {
        cout << "\nYou Lost! \n";
        cout << "\nThe word was: " << CHOICEWORD << endl;

    }

    else

    {

        cout << "\nYou Won!" << endl;
    }



}









void solucionguessmyword()
///Solucion Profe a Guess My Word
{

    const int MAX_ATTEMPTS = 3;
    int attempts = 0;

    vector<string> words;
    words.push_back("COMPUTADORA"); //Asi se hace mas dinamico. Pero tambi�n lo puedo definir como yo lo hice en llaves
    words.push_back("JUEGO");
    words.push_back("CODIGO");
    words.push_back("REFRIGERADOR");

    srand(time(NULL));
    int randomNumber = rand(); //va a agarrar un index (de 0 a 4 del vector)
    int wordsRandomIndex = (randomNumber % words.size()); //No necesitamos poner -1 (para que de 4 solo me muestre hasta 3). El Size ya lo hace
    string wordSelected = words[wordsRandomIndex];

    //cout << wordSelected << endl;

    random_shuffle(wordSelected.begin(), wordSelected.end());
    cout << wordSelected << endl;

    string correctWord;

    do
    {

        cin >> correctWord;
        transform(correctWord.begin(), correctWord.end(), correctWord.begin(), ::toupper); //Es para transformar el input por consola en MAYUSCULA
        cout << correctWord << endl;

        if (correctWord == words[wordsRandomIndex])
        {
            attempts++;
            cout << "\nAdivinaste la palabra!\n";
            break;
        }

        else
        {
            attempts++;
            cout << "Fallaste humano inepto, te quedan " << MAX_ATTEMPTS - attempts;

        }

    } while (attempts != MAX_ATTEMPTS);

    if (attempts == MAX_ATTEMPTS)
    {

        cout << "\nPerdiste, date de baja, la palabra era: \n";
        cout << words[wordsRandomIndex];

    }

    else

    {

        cout << "\nMUY BIEN!, Lo hiciste en: " << attempts << " intentos.";
    }



}



//////////////////////////////////////////////////////////////

void iterInventory()
{

    vector<string> inventory;
    inventory.push_back("Espada");
    inventory.push_back("Escudo");
    inventory.push_back("Martillo");
    inventory.push_back("Rifle");

    vector<string>::iterator myIterator; ///Mi Iterador lo llamamos myIterator. Este puede cambiar los valores (desordenarlos, etc.)
    vector<string>::const_iterator iter; ///Solo va a mostrar los datos

    cout << "\nTus Items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;

    }

    //Intercambiar elementos dentro del vector
    cout << "\nIntercambiaste tu " << inventory[2] << " por un arco"; //Este numero y el de la linea de abajo deben de ser iguales. Tambi�n puede funcionar con una variable
    myIterator = inventory.begin() + 2; //Este numero debe de ser igual al de arribita. Tambi�n puede funcionar con una variable.
    *myIterator = "Arco"; //Se pone * para que AGARRE el elemento que est� ah� y MOSTRARLO. No solo apuntar al espacio

    cout << "\nTus Items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;

    }

    //SIZE
    cout << "\nEl nombre del item " << *myIterator << " tiene "; //sin el asterisco, saldria error porque el cout no sabe que mostrar
    cout << (*myIterator).size() << " letras";

    cout << "\nEl nombre del item " << *myIterator << " tiene ";
    cout << (myIterator)->size() << " letras"; //-> Hace lo mismo que el codigo de arriba, solo cambia la sintaxis. el -> funciona como puntero para llamar a una funcion

    //INSERTAR NUEVO ELEMENTO
    cout << "\n\nRecuperaste la bomba robada ";
    inventory.insert(inventory.begin() + 2, "bomba"); //Es para meter cosas en nuestro vector ya sea al inicio, final, en medio, etc.

    cout << "\nTus Items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;

    }

    //DELETE
    cout << "\nTu " << inventory[1] << " fue destruido en batalla."; //Este numero y el de la linea de abajo deben de ser iguales. Tambi�n puede funcionar con una variable
    inventory.erase(inventory.begin() + 1); //Este numero y el de la linea de arriba deben de ser iguales. Tambi�n puede funcionar con una variable

    cout << "\nTus Items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << *iter << endl;

    }











}




void practicaguessmyword()
{
    vector <string>::const_iterator iter;
    string guess;
    string randword;

    //Inicio del Juego
    cout << "***Welcome to the game GUESS THE WORD***\n" << endl;
    cout << "How To Play:" << endl;
    cout << "-I will show you a set of disordered letters and you need to guess the word." << endl;
    cout << "-You have 3 chances to take a guess. If after 3 attempts you don't guess the correct word, you loose.\n" << endl;
    cout << "Are you ready?, Let's Play!\n" << endl;

    cout << "CATEGORY IS: THINGS YOU CAN FIND AT THE BEACH" << endl;

    vector<string> words = { "seahorse","palms","shark", "towel", "umbrella" };
    cout << "\n";

    //Ordenar de manera aleatoria los valores dentro del Vector
    srand(time(NULL));
    random_shuffle(words.begin(), words.end());

    //Seleccionar un valor Random del Vector
    int RandIndex = rand() % 5;
    cout << words[RandIndex]; //Depurar Resultado
    randword = words[RandIndex];

    cout << "\n";
    cout << "\n";

    cout << "-----------------------------------------------" << endl;
    //Desordenar la palabra seleccionada aleatoriamente del Vector
    random_shuffle(randword.begin(), randword.end());
    cout << "The disordered word you need to guess is :" << randword;
    cout << "\n";

    //Pedirle al jugadior su respuesta
    cout << "What is the hidden word here?\n" << endl;

    int life = 3;

    do {


        cin >> guess;

        //Validaci�n si la respuesta es correcta o no

        if (guess == words[RandIndex])

        {
            cout << "\nYou have that RIGHT!\n";
            life = life - 3;
        }

        else
        {
            cout << "\nThat is NOT a match!\n";
            life = life - 1;
            cout << "You only have " << life << " tries left!" << endl;
        }

    } while (life > 0);

    cout << "\nThe word was " << words[RandIndex] << endl;
    cout << "\nThanks for playing!\n";

}

////////////////////////////////////////////////////////////

void iterators()

{

    const int NUM_SCORES = 4;
    int score;

    vector <int>::const_iterator iter; /// Esta es la linea para crear el Iterator.Un iterador apunta a la direccion de memoria dentro de un vector. Se llama "iter". Es un apuntador 
    ///Sirve para recorrer los elementos dentro de un vector. Sin el *, solo apunta a un espacio de memoria. Con * ya agarra lo que hay ahi
    ///se declara como const_iterator para simplemente apuntar al espacio de memoria pero no modificar el valor que hay ahi

    vector<int> scores; // Esto es para crear el vector

    for (int i = 0; i < NUM_SCORES; i++) ///Ciclo para ingresar los valores dentro del vector
    {


        cout << "Score " << i + 1 << endl;
        cin >> score;
        scores.push_back(score);

    }

    for (iter = scores.begin(); iter != scores.end(); iter++) /// Ciclo para imprimir. Va a aumentarse a si mismo 

    {
        cout << *iter << endl; /// Se pone el asterisco para agarrar los valores. Sin el asterisco, solo apuntaria

    }

    ///Buscar Puntajes

    cout << "Buscar puntajes: Ingresa el puntaje que quieres buscar" << endl;
    cin >> score;

    iter = find(scores.begin(), scores.end(), score); //Desde donde quieres buscar, hasta donde quieres buscar y te retorna un valor encontrado. Que va a almacenar en Iter
    ///El Begin si agarra el primer elemento real ingresado.

    if (iter != scores.end()) /// Si llega hasta el final, quiere decir que nunca encontr� el score deseado. El Final es UN ESPACIO VACIO DESPUES del ultimo valor real ingresado. No confundirse.
    {
        cout << "\n Tu Puntaje se encuentra en el vector\n";
    }

    else
    {
        cout << "\nNo encontramos el puntaje que buscas\n";
    }

    //Random Shuffle//

    srand(time(NULL));
    random_shuffle(scores.begin(), scores.end());
    cout << "\nScores Mezclados\n";
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;

    }


    //Shuffle String Word
    //No Necesitamos crear un Vector
    //Es literalmente crear una variable nueva llamada word. Ya el random shuffle funciona porque String ya es un objeto que almacena letras
    //Solo funciona asi con el String

    string word = "espejo";
    random_shuffle(word.begin(), word.end());
    cout << word << endl;


    //Sort para ordenar nuestro vector//
    cout << "\nCambiar orden \n";
    sort(scores.begin(), scores.end());
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;

    }

    cout << "\nCambiar orden greater \n";
    sort(scores.begin(), scores.end(), greater<int>());
    for (iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout << *iter << endl;

    }


}




////////////////////////////////////////////////////////

void vectorReserve()
{

    vector<int> scores(10, 0); /// 10 es el numero de espacios y el cero es el valor en esos 10 espacios
    cout << "Vector size is : " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;

    scores.reserve(12); ///es para delimitar lo que yo quiero y no que lo agregue solito a su antojo
    scores.push_back(0);
    cout << "Vector size is : " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl; /// Aqui por naturaleza el vector agrega solito espacios extras

    scores.push_back(3); /// el 3 es el valor de ese espacio
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);

    cout << "Vector size is : " << scores.size() << endl;
    cout << "Vector capacity is: " << scores.capacity() << endl;



}

///////////////////////////////////////////////////////////



void vectorsPart1()
{
    /// Estas son las diferentes maneras de declarar un vector:
    // vector<string> mystuff = { "espada","martillo","bomba" }; Estoy creando un vector con esos 3 valores
    // vector<string> inventory(10); Solo estoy creando un vector vacio con 10 espacios
    // vector<string> inventory(10, "Empty"); le estoy diciendo que me cree 10 espacios y se llenen con la palabra Empty
    // vector<string> inventory(mystuff);Estoy creando un vector que tenga dentro los valores del primer vector

    vector<string> inventory;

    inventory.push_back("Espada"); //push.back a�ade un elemento al final de la cola del vector
    inventory.push_back("Escudo");
    inventory.push_back("Martillo");

    cout << "Tienes " << inventory.size() << " items en tu inventario" << endl; //me va a decir 3 porque son los 3 valores que meti arribita
    cout << "\n";


    ///// Iteration FOR

    for (unsigned int i = 0; i < inventory.size(); i++) // es un for para imprimir los valores dentro del vector. Unsigned es para que no tenga signos, no tome en cuent negativos, lo hace mas optimo.
                                                         // el "unsigned" quita los numeros negativos entonces me sirve para ahorrar memoria
    {                                                    // se empieza desde cero porque el primer valor del vector esta en Cero. Por eso
        cout << inventory[i] << endl;
    }

    cout << "\n";

    //EJERCICIO SI QUISIERA REEMPLAZAR EL PRIMER VALOR DEL VECTOR E IMPRIMIRLO CON UN WHILE

    cout << "Cambiaste tu " << inventory[0] << " por una Bomba" << endl;
    inventory[0] = "Bomba"; // asi es como cambiaria el valor de un espacio del vector


    cout << "\n";

    // si lo quisieramos hacer con un do while seria asi:
    ///// Iteration DO-WHILE
    int i = 0;
    do {

        cout << inventory[i] << endl;
        i++;

    } while (i < inventory.size());


    // For es para iterar entre una lista. Es para elementos contados, objetos contados. Ejemplo: imprimir una lista, etc.
    // Mientras que el While es para que se ejecute mientras se cumpla una condicion o mas de una condicion. 
    // Entonces en el While tenemos una condicion mas exacta pero aqui nos sirve mas el For. 

    cout << "\n";

    cout << inventory[0] << " tiene " << inventory[0].size() << " letras en el."; //inventory0.size se refiere al tama�o de digitos del elemento en una posicion en especifico

    cout << "Perdiste un item en la ultima batalla" << endl;
    inventory.pop_back(); /// para eliminar items dentro de nuestro vector se usa pop_back. SIEMPRE borra el del final.

    for (unsigned int i = 0; i < inventory.size(); i++) /// vamos a verificar con el for si lo de arribita es cierto

    {
        cout << inventory[i] << endl;
    }

    cout << "\n";

    cout << "Un enemigo ha robado todas tus armas" << endl;
    inventory.clear(); ///es para borrar TODO lo que esta dentro del vector

    cout << "\n";


    if (inventory.empty()) /// empty es para verificar si esta todo vacio
    {
        cout << "No tienes nada" << endl;
    }

    else
    {

        for (unsigned int i = 0; i < inventory.size(); i++) /// vamos a verificar con el for si lo de arribita es cierto

        {
            cout << inventory[i] << endl;
        }



    }

    cout << "\n";



    /////////////////PRACTICA: INGRESAR VALOR POR CONSOLA EN VECTOR E IMPRIMIRLOS///////////////////

    vector<string> INV(5);

    /// INGRESAR POR CONSOLA LOS VALORES 

    for (unsigned int i = 0; i < INV.size(); i++)

    {
        cout << "Ingresa el valor para el vector" << endl;
        cin >> INV[i]; ///Se usa i porque mi variable comienza con 0, que es la primera posicion del vector

    }

    cout << "\n";

    /// IMPRIMIR LOS VALORES QUE SE INGRESARON

    cout << "Los valores que se ingresaron en el vector son:" << endl;

    for (unsigned int i = 0; i < INV.size(); i++)

    {
        cout << INV[i] << endl;
    }


}