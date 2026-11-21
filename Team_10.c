
#include <stdio.h>

struct Food
{
    int id;
    char name[30];
    int price;
    int quantity;
    int amount;
};

struct Bill
{
    int orderNo;
    int total;
    int discount;
    int finalAmount;
    int payment;
};

struct Food menu[13] = {
    {1, "Burger", 50, 0, 0},
    {2, "Pizza", 100, 0, 0},
    {3, "Sandwich", 40, 0, 0},
    {4, "Cold Drink", 30, 0, 0},
    {5, "French Fries", 60, 0, 0},
    {6, "Maggi", 40, 0, 0},
    {7, "Chicken Burger", 100, 0, 0},
    {8, "Chicken Sandwich", 90, 0, 0},
    {9, "Chicken Pizza", 150, 0, 0},
    {10, "Chicken Nuggets", 120, 0, 0},
    {11, "Cold Coffee", 60, 0, 0},
    {12, "Hot Coffee", 40, 0, 0},
    {13, "Tea", 20, 0, 0}
};

int totalOrders = 0;
int totalSales = 0;

// Function to display menu
void displayMenu()
{
    int i;

    printf("\n----------------------- FOOD MENU -----------------------\n");
    printf("ID\tFood Item\t\tPrice\n");

    for(i = 0; i < 13; i++)
    {
        printf("%d\t%-20s Rs.%d\n",
        menu[i].id, menu[i].name, menu[i].price);
    }

    printf("---------------------------------------------------------\n");
}

// Function to take customer order
void takeOrder()
{
    int choice, quantity;

    while(1)
    {
        displayMenu();

        printf("Enter food ID (0 to finish): ");
        scanf("%d", &choice);

        if(choice == 0)
            break;

        if(choice < 1 || choice > 13)
        {
            printf("Invalid food ID! Try again.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        if(quantity <= 0)
        {
            printf("Invalid quantity!\n");
            continue;
        }

        menu[choice - 1].quantity += quantity;

        menu[choice - 1].amount =
        menu[choice - 1].price *
        menu[choice - 1].quantity;

        printf("Item added successfully!\n");
    }
}

// Function to calculate bill
void calculateBill(struct Bill *b)
{
    int i;

    b->total = 0;

    for(i = 0; i < 13; i++)
    {
        b->total += menu[i].amount;
    }

    if(b->total >= 500)
        b->discount = b->total * 10 / 100;
    else
        b->discount = 0;

    b->finalAmount = b->total - b->discount;
}

// Function to select payment method
void paymentMethod(struct Bill *b)
{
    printf("\nSelect Payment Method:\n");
    printf("1. Cash\n");
    printf("2. UPI\n");
    printf("3. Card\n");

    printf("Enter your choice: ");
    scanf("%d", &b->payment);

    if(b->payment < 1 || b->payment > 3)
    {
        printf("Invalid choice! Default payment: Cash\n");
        b->payment = 1;
    }
}

// Function to generate final receipt
void generateBill(struct Bill b)
{
    int i;

    printf("\n========================================\n");
    printf("             CANTEEN RECEIPT\n");
    printf("========================================\n");

    printf("Order Number: %d\n", b.orderNo);

    printf("----------------------------------------\n");
    printf("Food Item\tQty\tPrice\tAmount\n");
    printf("----------------------------------------\n");

    for(i = 0; i < 13; i++)
    {
        if(menu[i].quantity > 0)
        {
            printf("%-20s %d\t%d\t%d\n",
            menu[i].name,
            menu[i].quantity,
            menu[i].price,
            menu[i].amount);
        }
    }

    printf("----------------------------------------\n");
    printf("Total Amount: Rs.%d\n", b.total);
    printf("Discount: Rs.%d\n", b.discount);
    printf("Final Amount: Rs.%d\n", b.finalAmount);

    printf("Payment Method: ");

    if(b.payment == 1)
        printf("Cash\n");
    else if(b.payment == 2)
        printf("UPI\n");
    else
        printf("Card\n");

    printf("========================================\n");
    printf("       THANK YOU! VISIT AGAIN!\n");
    printf("========================================\n");
}

// Function to display daily sales report
void salesReport()
{
    printf("\n========== DAILY SALES REPORT ==========\n");
    printf("Total Orders: %d\n", totalOrders);
    printf("Total Sales: Rs.%d\n", totalSales);
    printf("========================================\n");
}

// Main function
int main()
{
    struct Bill b;
    int i, again = 1;

    printf("\n========================================\n");
    printf("       WELCOME TO COLLEGE CANTEEN\n");
    printf("========================================\n");

    while(again == 1)
    {
        // Reset previous order quantities
        for(i = 0; i < 13; i++)
        {
            menu[i].quantity = 0;
            menu[i].amount = 0;
        }

        b.orderNo = totalOrders + 1;

        printf("\nStarting New Order...\n");

        takeOrder();

        if(menu[0].quantity == 0 &&
           menu[1].quantity == 0 &&
           menu[2].quantity == 0 &&
           menu[3].quantity == 0 &&
           menu[4].quantity == 0 &&
           menu[5].quantity == 0 &&
           menu[6].quantity == 0 &&
           menu[7].quantity == 0 &&
           menu[8].quantity == 0 &&
           menu[9].quantity == 0 &&
           menu[10].quantity == 0 &&
           menu[11].quantity == 0 &&
           menu[12].quantity == 0)
        {
            printf("No items ordered!\n");
        }
        else
        {
            calculateBill(&b);
            paymentMethod(&b);
            generateBill(b);

            totalOrders++;
            totalSales += b.finalAmount;
        }

        printf("\nDo you want to serve another customer?\n");
        printf("Enter 1 for Yes or 0 for No: ");
        scanf("%d", &again);
    }

    salesReport();

    printf("\nCanteen Closed. Have a Nice Day!\n");

    return 0;
}
}