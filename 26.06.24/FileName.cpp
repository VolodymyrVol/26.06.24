#include <iostream>
using namespace std;


struct Element
{
    // Данные
    char data;
    // Адрес следующего элемента списка
    Element* Next;
};

// Односвязный список
class List
{
    // Адрес головного элемента списка
    Element* Head;
    // Адрес головного элемента списка
    Element* Tail;
    // Количество элементов списка
    int Count;

public:
    // Конструктор
    List();
    // Деструктор
    ~List();

    // Добавление элемента в список
    // (Новый элемент становится последним)
    void Add(char data);

    // Удаление элемента списка
    // (Удаляется головной элемент)
    void Del();
    // Удаление всего списка
    void DelAll();

    // Распечатка содержимого списка
    // (Распечатка начинается с головного элемента)
    void Print();

    // Получение количества элементов, находящихся в списке
    int GetCount();

    void AddInd(char c, int num);
    
    void DelInd(int ind);
    void Search(char obj);
};

List::List()
{
    // Изначально список пуст
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    // Вызов функции удаления
    DelAll();
}

int List::GetCount()
{
    // Возвращаем количество элементов
    return Count;
}

void List::AddInd(char c, int num)
{
    int i = 1;
    Element* temp = Head;
    while (i < num)
    {
        temp = temp->Next;
        i++;
    }
    Element* nElement = new Element;
    nElement->data = c;
    nElement->Next = temp->Next;
    temp->Next = nElement;
}

void List::DelInd(int ind)
{
    Element* temp = Head;
    Element* temp2 = Head;
    for (int i =1;i < ind; i++)
    {
        temp = temp->Next;
    }
    for (int i = 1; i < (ind - 1); i++)
    {
        temp2 = temp2->Next;
    }
    temp2->Next = temp->Next;
    delete temp;
}

void List::Search(char obj)
{
    Element* temp = Head;
    for (int i = 1;; i++)
    {
        temp = temp->Next;
        if (temp->Next != 0)
        {
            if (temp->data == obj)
            {
                cout << temp->data<< endl;
                break;
            }
        }
        else
        {
            break;
        }
    }
}

void List::Add(char data)
{
    // создание нового элемента
    Element* temp = new Element;

    // заполнение данными
    temp->data = data;
    // следующий элемент отсутствует
    temp->Next = NULL;
    // новый элемент становится последним элементом списка
    // если он не первый добавленный
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // новый элемент становится единственным
    // если он первый добавленный
    else {
        Head = Tail = temp;
    }
}

void List::Del()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // перебрасываем голову на следующий элемент
    Head = Head->Next;
    // удаляем бывший головной элемент
    delete temp;
}

void List::DelAll()
{
    // Пока еще есть элементы
    while (Head != 0)
        // Удаляем элементы по одному
        Del();
}

void List::Print()
{
    // запоминаем адрес головного элемента
    Element* temp = Head;
    // Пока еще есть элементы
    while (temp != 0)
    {
        // Выводим данные
        cout << temp->data << " ";
        // Переходим на следующий элемент
        temp = temp->Next;
    }

    cout << "\n\n";
}

// Тестовый пример
void main()
{
    // Создаем объект класса List
    List lst;
    lst.Add('H');
    lst.Add('e');
    lst.Add('l');
    lst.Add('l');
    lst.Add('o');
    lst.AddInd('x', 2);
    lst.DelInd(4);
    lst.Print();
    lst.Search('x');
}