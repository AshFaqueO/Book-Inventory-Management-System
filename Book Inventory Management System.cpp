#include<iostream>
using namespace std;
struct Book
{
    string isbn;
    string title;
    string author;
    string genre;
    double price;
    int stock;
    int totalCost;
};

void addNewBook(Book books[],int &numBooks)
{
    if(numBooks>=500)
    {
        cout<<"Error: Maximum number of books reached."<<endl;
        return;
    }
     Book newBook;
    cout << "Enter ISBN: ";
    getline(cin, newBook.isbn);
    cout << "Enter title: ";
    getline(cin, newBook.title);
    cout << "Enter author: ";
    getline(cin, newBook.author);
    cout << "Enter genre: ";
    getline(cin, newBook.genre);
    cout << "Enter price: ";
    cin >> newBook.price;
    cout << "Enter stock level: ";
    cin >> newBook.stock;
    books[numBooks++] = newBook;
    cout << "Book added successfully."<<endl;
}
void displayAllBooks(const Book books[],int numBooks)
{
    cout << "---------- All Books -----------"<<endl;

    for (int i = 0; i < numBooks; ++i)
    {
        cout << "ISBN: " << books[i].isbn << ", Title: " << books[i].title << ", Author: " << books[i].author << ", Genre: " << books[i].genre << ", Price: " << books[i].price << ", Stock: " << books[i].stock << endl;
    }
    }
void updateStock(Book books[],int numBooks)
{
    string isbn;
    int newStock;
    cout << "Enter ISBN of the book to update stock: ";
    getline(cin,isbn);
    int index=0;
    for (int i=0;i<numBooks;i++)
    {
        if (books[i].isbn == isbn) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Book not found."<<endl;
        return;
    }
    cout << "Enter new stock level: ";
    cin >> newStock;
    books[index].stock=newStock;
    cout << "Stock level updated successfully."<<endl;
}

void processSale(Book books[], int numBooks) {
    string isbn;
    int quantity;
    cout << "Enter ISBN of the book sold: ";
    getline(cin, isbn);
    int index =-1;
    for (int i = 0; i < numBooks; ++i) {
        if (books[i].isbn == isbn) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Book not found."<<endl;
        return;
    }
    cout << "Enter quantity sold: ";
    cin >> quantity;
    if (quantity > books[index].stock)
    {
        cout << "Error: Insufficient stock."<<endl;
        return;
    }
    books[index].stock-=quantity;
    books[index].totalCost = quantity*books[index].price;
    cout << "Total cost for the sale: $" << books[index].totalCost << endl;
}

void generateSalesReport(const Book books[], int numBooks) {
    cout << "----------- Sales Report -----------"<<endl;

    double totalSales = 0.0;
    for (int i = 0; i < numBooks; ++i) {
        if (books[i].stock < 0) {
            continue;
        }
        cout << "ISBN: " << books[i].isbn << ", Title: " << books[i].title << ", Book Remaining: " << books[i].stock << ", Remaining Sales: " << (books[i].stock * books[i].price) << endl;
        totalSales += books[i].totalCost;
    }
    cout << "-----------------------------------------------"<<endl;
    cout << "total Sales: $" << totalSales << endl;
}
int main() {
    const int MAX_BOOKS = 500;
    Book books[MAX_BOOKS];
    int numBooks = 0;
    char choice;

    do
    {
        cout<<endl;
        cout << "----------- Bookstore Inventory Management System -----------"<<endl;
        cout << "1. Add New Book"<<endl;
        cout << "2. Display All Books"<<endl;
        cout << "3. Update Stock"<<endl;
        cout << "4. Process Sale"<<endl;
        cout << "5. Generate Sales Report"<<endl;
        cout << "6. Exit Program"<<endl;
        cout << "Enter your choice:"<<endl;
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case '1':
                addNewBook(books, numBooks);
                break;
            case '2':
                displayAllBooks(books, numBooks);
                break;
            case '3':
                updateStock(books, numBooks);
                break;
            case '4':
                processSale(books, numBooks);
                break;
            case '5':
                generateSalesReport(books, numBooks);
                break;
            case '6':
                cout << "Exiting program. Thank you."<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again."<<endl;
        }
    }
    while(choice != '6');

    return 0;
}
