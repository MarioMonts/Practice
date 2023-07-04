/////Este archivo contiene las practicas hechas en clase con el profesor.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <clocale>

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
void tiktaktok();

//References
void badSwap(int x, int y);
void goodSwap(int& x, int& y);
void display(const vector<string>& vec);

//Funcion Examen II
string GetRandomItem(vector<string>& items);
void DisplayInventory(vector<string>& inventory);
bool AskYesNo(string question);
void ShowMenu();
int GuessParams(string question, int a, int b = 1);
void ReplaceItem(vector<string>& inventory, string itemFound);
void BuySpace(vector<string>& inventory, unsigned int& gems, string itemFound);
void examenII();

//Constantes Examen II
const int MAX_ITEMS = 6; //va constante porque el valor va a ir bajando.
const int SPACE_COST = 6; //va constante porque el valor va a ir bajando.
const int FREE_ITEMS = 3; //va constante porque el valor va a ir bajando.




//Punteros 

int main()
{
    //Un puntero de tipo INT NO puede apuntar a una variable de tipo String
    //Punteros, son como referencias pero mas dinamicos en cuestion de memoria. Al apuntar.
    //Simplemente apuntan a un espacio de memoria y obtienen su valor
    std::setlocale(LC_ALL, "es_ES.UTF-8");

    //Los punteros siempre por sintaxis siempre necesitan comenzar con la P
    //No podemos declarar un puntero sin antes definirlo. En este caso es score
    //declaracion de puntero para que apunte arriba (variable score). Apunta al espacio de memoria, no a lo que hay ahi.
    //Puntero con ENTEROS
    int score = 1000;
    int* pScore = &score; //Siempre debe de llevar el & en el puntero

    //Direccion de memoria: Para ver el ESPACIO de memoria donde esta almacenado la variable score
    cout << &score << endl; //0084F79C
    cout << pScore << endl; //0084F79C

    //Contenido de la memoria: Me imprimiria el VALOR que en este caso es el 1000
    cout << score << endl; //1000
    cout << *pScore << endl; //1000

    score += 500;

    //Contenido de memoria
    cout << score << endl; //1500
    cout << *pScore << endl; //1500

    *pScore += 500;
    //Contenido de memoria
    cout << score << endl; //2000
    cout << *pScore << endl; //2000

    //Los punteros pueden cambiar a donde apuntan. 
    //NEW SCORE
    int newScore = 5000;
    pScore = &newScore; //Estoy cambiando a donde apunta mi puntero

    //Direccion de memoria
    cout << &newScore << endl; //0036F768
    cout << pScore << endl; //0036F768

    //Contenido de la memoria
    cout << newScore << endl; //5000
    cout << *pScore << endl; //5000

    //Ahora haremos puntero con STRING

    string str = "score";
    string* pStr = &str;

    cout << str << endl; //score
    cout << *pStr << endl; //score

    cout << str.size() << endl; // 5 Esto imprime el tamaño del valor de la variable
    cout << (*pStr).size() << endl;//5 Esto es para imprimir el tamaño valor de lo que tiene el puntero
    cout << pStr->size() << endl; //5 Esto es la misma sintaxis que la linea anterior

    //Ahora haremos Punteros CONSTANTE
    int lives = 5;
    int* const plives = &lives;

    //NO VALID porque se esta cambiando la direccion a la que apunta y CONST justo no quiere eso
    //int maxLives = 10;
    //pLives = &maxlives;


    //A pointer to a Constant. Protege el contenido de lo que apunta el puntero
    int initialDefense = 100;
    const int* pNumber; //Declaro puntero

    int defense = 32; //Creo variable
    pNumber = &defense; // Lo igualamos a Defense

    //VALID
    defense *= 2;
    cout << defense << endl;
    cout << *pNumber << endl;

    //NO VALID
    //*pNumber *=2;

    //Constant pointer to a constant

    int bonus = 40;
    const int* const pBonus = &bonus;

}


void examenII()

{

    //Solucion Examen II - Profesor

    std::setlocale(LC_ALL, "es_ES.UTF-8"); //Linea para que al poner simbolos en Español, no me salgan cosas raras en consola
    unsigned int gems = 8; // Se usa unsigned porque no queremos que se almacenen numeros Negativos

    //Items
    vector <string> items = { "espada", "martillo", "bomba", "escudo" };

    //Inventory
    vector <string> inventory;
    inventory.reserve(MAX_ITEMS); //Reserve se usa para reservar espacios de memoria para que el vector no haga lo que quiera y no incremente los espacios. Para que unicamente sean 6 en este caso
    vector <string> ::const_iterator iter; //creamos un Iterador para recorrer nuestros ciclos como con un For

    bool isContinue;

    do {
        //Recoger de manera aleatoria items 
        cout << "\n--INVENTARIO--\n";
        cout << "Gemas: " << gems << endl;
        string itemFound = GetRandomItem(items);

        cout << "Has encontrado un(a) " << itemFound << "!!\n";
        if (inventory.size() >= FREE_ITEMS)
        {

            ShowMenu();
            int option = GuessParams("\nElige un numero ", 3);

            switch (option)
            {
            case 1:

                ReplaceItem(inventory, itemFound);
                break;

            case 3:

                BuySpace(inventory, gems, itemFound);
                break;

            default:
                break;
            }

        }

        else
        {

            inventory.push_back(itemFound);
        }



        //DisplayItems
        DisplayInventory(inventory);

        isContinue = AskYesNo("Seguir explorando?");

    } while (isContinue);

    cout << "\nVuelve pronto!!\n";


}

//Funcion para comprar mas espacio
void BuySpace(vector<string>& inventory, unsigned int& gems, string itemFound)

{

    if (gems >= SPACE_COST) //las gemas me daba error, asi que tuve que meterlas como argumento en mi funcion
    {

        cout << "\n Espacio comprado con exito!!\n";
        inventory.push_back(itemFound);
        gems -= SPACE_COST; //la tenemos como global, por eso se puede usar. Solo las constantes se pueden definir como globales
        //gems = gems - SPACE_COST; es lo mismo que arriba 
        // gems --; es para qeu se reste en uno nada mas
    }

    else

    {

        cout << "\nNo tienes gemas suficientes !!\n";


    }


}

//Funcion para reemplazar un objeto

void ReplaceItem(vector<string>& inventory, string itemFound) //el "&" es para que entre como referencia para que el original se modifique y no quede como copia. Tambien le ponemos el itemFound porque se usa en la referencia mas abajo
//sin el &, estariamos dejando el inventory como copia y para que surta efecto, hasta abajo tendriamos que poner un "return inventory". Pero esto usa mas memoria

{
    vector<string>::iterator iter; //No es const porque vamos a reemplazar un valor. Un iterador es un apuntador a un espacio de memoria (array, vector, etc.)
    int itemChosen = 0;
    cout << "\n¿Que item deseas reemplazar?\n";
    DisplayInventory(inventory);
    cin >> itemChosen; //define la posicion donde yo quiero reemplazar mi objeto
    iter = inventory.begin() + itemChosen; //el iterador esta apuntando al inicio de mi vector mas la posicíon elegida
    *iter = itemFound;//agarramos con el puntero el contenido de esa posicion y la igualamos al itemfound

}







//Funcion para obtener items aleatorios de los 4 que tenemos arriba

string GetRandomItem(vector<string>& items)
{
    srand(time(NULL));
    int itemRandomIndex = (rand() % items.size());
    string itemSelected = items[itemRandomIndex];

    return itemSelected;

}

//Funcion para mostrar los items aleatorios encontrados

void DisplayInventory(vector<string>& inventory)
{

    vector<string>::const_iterator iter;
    int i = 0;
    cout << "\n--Tus items--\n";
    for (iter = inventory.begin(); iter != inventory.end(); iter++)
    {
        cout << i << "_" << *iter << endl; //se pone * para que la mano del iter no solo apunte, sino agarre
        i++;
    }


}








//Funcion para preguntar Si o No

bool AskYesNo(string question)
{

    char answer;

    do
    {
        cout << "\n" << question << "(y/n)";
        cin >> answer;

    } while (answer != 'y' && answer != 'n');

    if (answer == 'y')
    {
        return true;

    }

    return false;


}

//Funcion para el Menu

void ShowMenu()

{

    cout << "\nYa no tienes espacio para mas objetos, que te gustaria hacer: \n";
    cout << "\n1. Reemplazar objeto.";
    cout << "\n2. Continuar sin el objeto.";
    cout << "\n3. Anadir un espacio por " << SPACE_COST << " gemas";

}


//Funcion del GuessMyNumber

int GuessParams(string question, int a, int b)
{

    string input;
    bool isValid = false;
    // int num = 0; /// Esta variable solo existe dentro de la funcion. Por lo tanto no puede usarse en el main
    //si quisiera una variable global (que funcione en todos lados), tendria que ir arriba del main. Pero esto no es buena practica
    //nunca hacer globales. Hay que hacer variables constantes. 

    //Funciona al revés tambié, si pusiera una variable de main aquí, no la reconocería la función

    do {

        cout << question << "entre " << b << " y " << a << endl;
        getline(cin, input); //se usa para que el jugador meta strings con espacios
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (char c : input) // forma corta de hacer el for. Todo se almacena en la c hasta que se recorre todo el input

        {
            if (isdigit(c)) // el ! es para negar algo, es lo mismo a isdigit = false
            {
                isValid = true;
                break;
            }

        }


        if (!isValid)
        {
            cout << "Entrada invalida, por favor elige solo numeros.";

        }

    } while (!isValid || input.empty());

    // while (num > a || num < b); //el AND aqui no funcionaba porque no era posible. Se usa un OR

    return stoi(input); //String to Int es par aconvertir un string a un entero

}


void tiktaktok()

{


    char player1; //OJO - ESTE ES CHAR PORQUE LOS VALORES DE MI MATRIZ ESTÁN EN COMILLAS, NO SON NUMEROS
    char player2; //OJO - ESTE ES CHAR PORQUE LOS VALORES DE MI MATRIZ ESTÁN EN COMILLAS, NO SON NUMEROS


    cout << "\n---Welcome to the Game TIC TAC TOE, let's play!---\n";
    cout << "\nPlayer 1, you are playing with O's in the board";
    cout << "\nPlayer 2, you are playing with X's in the board";

    cout << "\n";


    //Nota, nunca hacer VARIABLES fuera del main. Solo las CONSTANTES que no cambian, podrian definirse fuera del main.

    //Codigo para crear la matriz

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

        //Interaccion con el jugador 1

        cout << "\nPlayer 1 Turn:";
        cout << "\nWhich space in the board you want to fill in?";
        cout << "\nChoose a number from the board\n";
        cin >> player1;
        system("cls");

        if (player1 != 'X')

        {

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




        }

        else
        {

            cout << "invalid option. You have lost your turn" << endl;

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


        //Interaccion con el jugador 2

        cout << "\nPlayer 2 Turn:";
        cout << "\nWhich space in the board you want to fill in?";
        cout << "\nChoose a number in the board\n";
        cin >> player2;
        system("cls");

        if (player2 != 'O')
        {

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


        }

        else
        {

            cout << "invalid option. You have lost your turn" << endl;

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


    cout << "\nThe board is already full!" << endl;

    //Determinacion del jugador ganador lado horizontal

    cout << "\n";

    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')

        cout << "\nPlayer 1 Wins!";


    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')

        cout << "\nPlayer 2 Wins!";


    if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')

        cout << "\nPlayer 2 Wins!";


    if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')

        cout << "\nPlayer 2 Wins!";

    //Determinacion del jugador ganador lado vertical


    if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')

        cout << "\nPlayer 2 Wins!";


    if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')

        cout << "\nPlayer 2 Wins!";


    if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')

        cout << "\nPlayer 2 Wins!";


    //Determinacion del jugador ganador cruzado 


    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')

        cout << "\nPlayer 2 Wins!";


    if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')

        cout << "\nPlayer 1 Wins!";

    if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')

        cout << "\nPlayer 2 Wins!";

    cout << "\n";


    cout << "\nTHANKS FOR PLAYING!";

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
    words.push_back("COMPUTADORA"); //Asi se hace mas dinamico. Pero también lo puedo definir como yo lo hice en llaves
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
    cout << "\nIntercambiaste tu " << inventory[2] << " por un arco"; //Este numero y el de la linea de abajo deben de ser iguales. También puede funcionar con una variable
    myIterator = inventory.begin() + 2; //Este numero debe de ser igual al de arribita. También puede funcionar con una variable.
    *myIterator = "Arco"; //Se pone * para que AGARRE el elemento que está ahí y MOSTRARLO. No solo apuntar al espacio

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
    cout << "\nTu " << inventory[1] << " fue destruido en batalla."; //Este numero y el de la linea de abajo deben de ser iguales. También puede funcionar con una variable
    inventory.erase(inventory.begin() + 1); //Este numero y el de la linea de arriba deben de ser iguales. También puede funcionar con una variable

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

        //Validación si la respuesta es correcta o no

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

    if (iter != scores.end()) /// Si llega hasta el final, quiere decir que nunca encontró el score deseado. El Final es UN ESPACIO VACIO DESPUES del ultimo valor real ingresado. No confundirse.
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

    inventory.push_back("Espada"); //push.back añade un elemento al final de la cola del vector
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

    cout << inventory[0] << " tiene " << inventory[0].size() << " letras en el."; //inventory0.size se refiere al tamaño de digitos del elemento en una posicion en especifico

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