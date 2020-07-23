struct Table{
    bool isOccupied; // Is the table occupied: if occupied - true, if free - false
    double price; // Price in roubles
    char[25] material; // What material is the table made of
    char[25] colour; // ASCII format of  colour
    int numberOfBoxes; // Quantity of boxes
};

// keep something
void keepThings(Table*);

// Visualization of a table
void view (Tabble*);

