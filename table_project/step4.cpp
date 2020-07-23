#include <cstdio>

struct Table {
    bool isOccupied; /* Is the table occupied: if occupied - true, if free - false */
    double price;  /* Price in roubles */
    const char *material; /* What material is the table made of */
    const char *colour; /* colour */
    int numberOfBoxes; /* Quantity of boxes */
    int complement;
    union {
        bool addOn; //mark = 0
        bool stand; //mark = 1
        bool screen; // mark = 2
    };
};


/* Initialization of a table */

void init(Table *table,
          bool isOccupied = true,
          double price = 1499.99,
          const char *material = "wood\0",
          const char *colour = "black\0",
          int numberOfBoxes = 4,
          int complement = 0) {
    table->isOccupied = isOccupied;
    table->price = price;
    table->material = material;
    table->colour = colour;
    table->numberOfBoxes = numberOfBoxes;
    table->complement = complement;
    if (table->complement == 0) {
        table->addOn = true;
    } else if (table->complement == 1) {
        table->stand = true;
    } else {
        table->screen = true;
    }
}

/* Visualization of a table */
void view(Table *table) {
    if (table->isOccupied)
        printf("The table type is occupied\n");
    else {
        printf("The table type is free\n");
    }
    printf("The table price = %f rubles\n", table->price);
    printf("The material of table = %s \n", table->material);
    printf("The colour of table = %s \n", table->colour);
    printf("The table has %d boxes\n", table->numberOfBoxes);
    if (table->complement == 0) {
        printf("The table has addon\n");
    } else if (table->complement == 1) {
        printf("The table has stand\n");
    } else {
        printf("The table has screen\n");

    }

}

/* keep something */
void keepThings(Table *table) {
    if (table->isOccupied) {
        printf("Making table free from things\n");
        table->isOccupied = false;
    } else {
        printf("The table starts to keep things\n");
        table->isOccupied = true;


    }
}

int main() {
    Table ParentTable, KidTable;
    init(&KidTable);
    view(&KidTable);
    keepThings(&KidTable);
    keepThings(&KidTable);
    printf("%c", '\n');
    init(&ParentTable, true, 5650, "metal\0", "white\0", 8, 1);
    view(&ParentTable);
    keepThings(&ParentTable);
    keepThings(&ParentTable);
    return 0;
}
