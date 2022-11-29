#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define NAME_MAX_LENGTH 100

struct Node
{
    string c_name;      // country name and it must be less than 100 character
    int c_cordinate[2]; // country longitude
    long c_pop;         // country popluation
    float c_temp;       // country average temperature
    struct Node *next;
};

struct Node *head = new Node(); // points to the added node

void append_record(string c_name, int c_cordinate[], long c_pop, float c_temp)
{
    /* allocate node */
    Node *add_c = new Node();

    add_c->c_name = c_name; // add  name
    add_c->c_cordinate[0] = c_cordinate[0];
    add_c->c_cordinate[1] = c_cordinate[1];
    add_c->c_pop = c_pop;
    add_c->c_temp = c_temp;
    add_c->next = NULL;

    if (head == NULL) // enter list to add node
    {
        add_c->next = head;
        head = add_c;
    }
    else // move to the next to add node
    {
        Node *c = head;
        while (c->next != NULL)
        {
            c = c->next;
        }
        add_c->next = c->next;
        c->next = add_c;
    }

    cout << "\tRecord Inserted Successfully\n";
}

void search_by_name(string c_name)
{
    if (!head) // list empty
    {
        cout << "\tCountry not found\n";
        return;
    }
    else
    {
        Node *N = head;
        if (N == NULL) // country doesn't exist
        {
            cout << "\tCountry not found\n";
            return;
        }
        else
        {
            while (N)
            {
                if (N->c_name == c_name) // country found
                {
                    cout << "\tCountry name : \t"
                         << N->c_name << endl;
                    cout << "\tCountry longtitude : \t"
                         << N->c_cordinate[0] << endl;
                    cout << "\tCountry latitude : \t"
                         << N->c_cordinate[1] << endl;
                    cout << "\tCountry population : \t"
                         << N->c_pop << endl;
                    cout << "\tCountry temparature : \t"
                         << N->c_temp << endl;
                }
                N = N->next; // continue searching
            }
        }
    }
}

void search_by_Coordinate(int c_cordinate[])
{
    if (!head) // list empty
    {
        cout << "\tCountry not found\n";
        return;
    }
    else
    {
        Node *N = head;
        if (N == NULL) // country doesn't exist
        {
            cout << "\tCountry not found\n";
            return;
        }
        else
        {
            while (N)
            {
                if ((N->c_cordinate[0] == c_cordinate[0]) && (N->c_cordinate[1] == c_cordinate[1])) // if both x and y match the given
                {
                    cout << "\tCountry name \t"
                         << N->c_name << endl;
                    cout << "\tCountry longtitude \t"
                         << N->c_cordinate[0] << endl;
                    cout << "\tCountry latitude \t"
                         << N->c_cordinate[1] << endl;
                    cout << "\tCountry population \t"
                         << N->c_pop << endl;
                    cout << "\tCountry temperature \t"
                         << N->c_temp << endl;
                }
                N = N->next; // continue search
            }
        }
    }
}

int Delete_Recode_By_Name(string c_name)
{
    Node *N = head;
    Node *p = NULL;

    if (N != NULL && N->c_name == c_name) // it's the first node
    {
        head = N->next;
        delete N;

        cout << "\tRecord deleted successfully\n";
        return 0;
    }

    // not the first node
    while (N != NULL && N->c_name != c_name)
    {
        p = N;
        N = N->next;
    }
    if (N == NULL) //
    {
        cout << "\tRecord does not exist\n";
        return -1;
        p->next = N->next;

        delete N;
        cout << "\tRecord deleted successfully\n";
        return 0;
    }
    return 1;
}

int Delete_Recode_By_Cordinate(int c_cordinate[])
{
    Node *N = head;
    Node *p = NULL;

    if ((N != NULL) && (N->c_cordinate[0] == c_cordinate[0]) && (N->c_cordinate[1] == c_cordinate[1]))
    {
        head = N->next;
        delete N;

        cout << "\tRecord deleted succesfully\n";
        return 0;
    }

    // Deletion Other than Begin (not the first)
    while ((N != NULL) && (N->c_cordinate[0] == c_cordinate[0]) && (N->c_cordinate[1] == c_cordinate[1]))
    {
        p = N;
        N = N->next;
    }
    if (N == NULL)
    {
        cout << "\tRecord does not exist\n";
        return -1;
        p->next = N->next;

        delete N;
        cout << "\tRecord deleted successfully\n";
        return 0;
    }
    return 1;
}

void printList()
{
    Node *p = head;
    int i;
    int char_small, char_capital;
    if (p == NULL) // list is empty
    {
        cout << "\tNo records available\n";
    }
    else
    {
        // Until p is not NULL
        char_capital = 65;
        char_small = 97;
        for (i = 0; i < 26; i++)
        {
            while (p != NULL)
            {
                char first_char = p->c_name[0];

                if (int(first_char) == char_small || int(first_char) == char_capital)
                {
                    cout << "\tName :\t\t\t" << p->c_name << endl;
                    cout << "\tLongitude :\t\t" << p->c_cordinate[0] << endl;
                    cout << "\tLatitude :\t\t" << p->c_cordinate[1] << endl;
                    cout << "\tPopulation :\t\t" << p->c_pop << endl;
                    cout << "\tAverage Temperatute :\t" << p->c_temp << endl;
                    break;
                }

                p = p->next;
            }
                p = head;
                char_small++;
                char_capital++;
        }
    }
}

string convertToString(char *a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++)
    {
        s = s + a[i];
    }
    return s;
}

int main()
{

    /* Start with the empty list */
    head = NULL;

    int option_select, i, j, c_exit = 0, s, l;
    int c_cordinate[2];
    char r_name[NAME_MAX_LENGTH] = {};
    string c_name;
    long c_pop;
    float c_temp;
    int c_arrange[2] = {0};

    do
    {
        cout << "\n\t\tCountry Record Database "
                "\n\n\tPress\n"
                "\t1 to add new country\n"
                "\t2 to Delete information of country by name\n"
                "\t3 to Delete information of country by coordinate \n"
                "\t4 to search and display country info by name\n"
                "\t5 to search and display country info by coordinate\n"
                "\t6 to Print all countries in alphabetical order \n"
                "\t7 Exit\n";
        cout << "\n\tEnter your Choice : ";
        cin >> option_select;
        cout << endl;
        switch (option_select)
        {
        case 1:
            cout << "\tadd new country :\n"
                 << endl;
            cout << "\tEnter country name it must be less than 100 characters : ";
            cin.getline(r_name, NAME_MAX_LENGTH);
            cin.getline(r_name, NAME_MAX_LENGTH);

            c_arrange[0] = c_arrange[1];
            c_arrange[1] = int(r_name[0]);
            cout << "first number" << c_arrange[0] << endl;
            cout << "first number" << c_arrange[1] << endl;
            c_name = convertToString(r_name, NAME_MAX_LENGTH);
            cout << endl
                 << "\tEnter array of coordinate " << endl;
            cout << "\tEnter longitude :";
            cin >> c_cordinate[0];
            cout << endl;
            cout << "\tEnter latitude :";
            cin >> c_cordinate[1];
            cout << endl;
            cout << "\tEnter country population :";
            cin >> c_pop;
            cout << endl
                 << "\tEnter country average temperature :";
            cin >> c_temp;
            cout << endl;

            // this function will call insert to add country information
            append_record(c_name, c_cordinate, c_pop, c_temp);

            break;
        case 2:
            cout << "\tdelete by name :\n"
                 << endl;
            cout << "\tEnter name of country you want to delete" << endl;
            cin.getline(r_name, NAME_MAX_LENGTH);
            cin.getline(r_name, NAME_MAX_LENGTH);
            c_name = convertToString(r_name, NAME_MAX_LENGTH);
            cout << endl;
            s = Delete_Recode_By_Name(c_name);
            if (s == 0)
            {
                cout << "\tRecord Deleted " << endl;
            }
            break;
        case 3:
            cout << "\tdelete by coordinate :\n"
                 << endl;
            cout << "\tEnter coordinate of country you want to delete" << endl;
            cout << "\tEnter longitude" << endl;
            cin >> c_cordinate[0];
            cout << endl
                 << "\tEnter latitude" << endl;
            cin >> c_cordinate[1];
            cout << endl;
            l = Delete_Recode_By_Cordinate(c_cordinate);
            if (l == 0)
            {
                cout << "\tRecord Deleted " << endl;
            }
            break;
        case 4:
            cout << "\tsearch by name :\n"
                 << endl;
            cout << "\tEnter name of country you want to search" << endl;
            cin.getline(r_name, NAME_MAX_LENGTH);
            cin.getline(r_name, NAME_MAX_LENGTH);
            c_name = convertToString(r_name, NAME_MAX_LENGTH);
            cout << endl;
            search_by_name(c_name);
            break;
        case 5:
            cout << "\tsearch by coordinate :\n"
                 << endl;
            cout << "\tEnter coordinate of country you want to search" << endl;
            cout << "\tEnter longitude" << endl;
            cin >> c_cordinate[0];
            cout << endl
                 << "\tEnter latitude" << endl;
            cin >> c_cordinate[1];
            cout << endl;
            search_by_Coordinate(c_cordinate);
            break;
        case 6:
            cout << "\tprint countries alphabetically :\n"
                 << endl;
            printList();
            break;
        case 7:
            c_exit = 1;
            break;
        }
    } while (c_exit == 0);
    cout << "\t\tprogram terminated" << endl;
}
