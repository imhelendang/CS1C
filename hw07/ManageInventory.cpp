#include "ManageInventory.h"

ManageInventory::~ManageInventory() {
    for(int i = 0; i < size; i++){
        delete p_pInventoryItems[i];
    }
    delete [] p_pInventoryItems;
}


/* Copy constructor. */
ManageInventory::ManageInventory(const ManageInventory& copied_item) {
    int index = 0;
    while(index < count) {
        copied_item.p_pInventoryItems[index]->item = p_pInventoryItems[index]->item;
        copied_item.p_pInventoryItems[index]->price = p_pInventoryItems[index]->price;
        copied_item.p_pInventoryItems[index]->quanity = p_pInventoryItems[index]->quanity;
    }
}

string ManageInventory::get_item(int index) const {
    return p_pInventoryItems[index]->item;
}

double ManageInventory::get_price(int index) const {
    return p_pInventoryItems[index]->price;
}

int ManageInventory::get_quanity(int index) const {
    return p_pInventoryItems[index]->quanity;
}

void ManageInventory::addItem() {

    string item;
    double price;
    int quan;

    /* Open input file. */
    ifstream inFile;
    inFile.open("text.txt");

    /* Check the file is open, mean available to read. */
    if (!inFile) {
		cout << "\n*ERROR!* Some errors occur while trying to open input file!\n\n";
	}
	else {

        cout <<"error!\n";
        /* Keep reading from a file when it hasn't reached the end of the file and index is in the valid range. */
		while(!inFile.eof() && count < size) {
            getline(inFile, item);
            inFile >> quan;
            inFile >> price;
            inFile.ignore(1000, '\n');
            p_pInventoryItems[count] = new Item {item, price, quan};
            count++;    
        }
	}

    /* Close input file. */
    inFile.close(); 
}

void reciept(ManageInventory *items, int cart[], int quan_wants[], string name) {

    system("clear");                                             /* Clear screen.         */
    cout << fixed << showpoint << right << setprecision(2);      /* set up number format. */

    /* Temporary variables. */
    char confirm;
    int i = 0;
    double sum = 0, total = 0;

    cout << left << "= \t\t\t\t\t RECIEPT \t\t\t\t\t    =" << endl;
    cout << "= ========================================================================================= =\n";
    cout << left << "= For " << name << ", current have: \t\t\t\t\t\t\t\t    =" << endl;

    while( i < items->count ) {
        if(cart[i] != -1 && quan_wants[i] != -1) {
            cout << left <<  "= " << setw(55) << items->get_item(cart[i]) << "$ " << setw(8) << items->get_price(cart[i]) << "     " << setw(2) << quan_wants[cart[i]] << "(x of this items) =" << endl;
            sum = quan_wants[cart[i]] *  items->get_price(cart[i]);
            total += sum;
        }
        i++;
    }

    cout << "= ========================================================================================= =\n";
    cout << "= Grand total:                                           $ " << setw(33) << total << "=" << endl;
    cout << "= Tax:                                                   $ " << setw(33) << total*TAX << "=" << endl;
    cout << "= Grand total with tax:                                  $ " << setw(33) << total+(total*TAX) << "=" << endl;
    cout << "= ========================================================================================= =\n";

    /* Ask for confirmation. */
    cout << "= Confirm the transaction (y/Y or n/N): ";
    cin >> confirm;
    cin.ignore(1000, '\n'); 

    /* Check the input. */
    while(confirm != 'n' && confirm != 'N' && confirm != 'y' && confirm != 'Y') {
        cout << "You have entered an invalid choice. Please enter y/Y for yes or n/N for no." << endl << endl;
    }

    /* Only update the inventory when the user confirms the transaction. */
    if(confirm == 'Y' || confirm == 'y') {
        
        i = 0;
        while( i < items->count ) {

            if(cart[i] != -1 && quan_wants[i] != -1) {
                items->p_pInventoryItems[cart[i]]->quanity -= quan_wants[i];
            }
            i++;

        }
    }
    return;
} 

/* Overloading operator. */
ostream & operator<<(ostream& os, const ManageInventory& other) {

    os << fixed << showpoint << right << setprecision(2); //set up number format
    int index = 0;
    while(index < TOTAL_ITEMS) {

        os << "= -------------------------------------------------------------------------------------------------------- =\n";
        os << "= Item #" << setw(2) << index+1 << "     ";
        os << left <<  "=  " << setw(55) << other.get_item(index) << "=  $ " << setw(8) << other.get_price(index) << "=        " << setw(2) << other.get_quanity(index) << "          =" << endl;
        index++;
    }

    return os;
}