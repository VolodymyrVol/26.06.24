#include <iostream>
using namespace std;


struct Element
{
    // ������
    char data;
    // ����� ���������� �������� ������
    Element* Next;
};

// ����������� ������
class List
{
    // ����� ��������� �������� ������
    Element* Head;
    // ����� ��������� �������� ������
    Element* Tail;
    // ���������� ��������� ������
    int Count;

public:
    // �����������
    List();
    // ����������
    ~List();

    // ���������� �������� � ������
    // (����� ������� ���������� ���������)
    void Add(char data);

    // �������� �������� ������
    // (��������� �������� �������)
    void Del();
    // �������� ����� ������
    void DelAll();

    // ���������� ����������� ������
    // (���������� ���������� � ��������� ��������)
    void Print();

    // ��������� ���������� ���������, ����������� � ������
    int GetCount();

    void AddInd(char c, int num);
    
    void DelInd(int ind);
    void Search(char obj);
};

List::List()
{
    // ���������� ������ ����
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    // ����� ������� ��������
    DelAll();
}

int List::GetCount()
{
    // ���������� ���������� ���������
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
    // �������� ������ ��������
    Element* temp = new Element;

    // ���������� �������
    temp->data = data;
    // ��������� ������� �����������
    temp->Next = NULL;
    // ����� ������� ���������� ��������� ��������� ������
    // ���� �� �� ������ �����������
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // ����� ������� ���������� ������������
    // ���� �� ������ �����������
    else {
        Head = Tail = temp;
    }
}

void List::Del()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ������������� ������ �� ��������� �������
    Head = Head->Next;
    // ������� ������ �������� �������
    delete temp;
}

void List::DelAll()
{
    // ���� ��� ���� ��������
    while (Head != 0)
        // ������� �������� �� ������
        Del();
}

void List::Print()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ���� ��� ���� ��������
    while (temp != 0)
    {
        // ������� ������
        cout << temp->data << " ";
        // ��������� �� ��������� �������
        temp = temp->Next;
    }

    cout << "\n\n";
}

// �������� ������
void main()
{
    // ������� ������ ������ List
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