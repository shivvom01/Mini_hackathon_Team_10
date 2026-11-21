PSEUDO CODE:-
START

DECLARE structure Food: id, name, price, quantity, amount
DECLARE structure Bill: orderNo, total, discount, finalAmount, payment
DECLARE menu = list of 13 foods (id, name, price, quantity = 0, amount = 0)
SET totalOrders = 0
SET totalSales = 0

FUNCTION displayMenu()
    PRINT "FOOD MENU"
    FOR i = 1 TO 13
        PRINT id, name, price of menu[i]
    END FOR
END FUNCTION

FUNCTION takeOrder()
    REPEAT forever
        CALL displayMenu()
        INPUT choice
        IF choice = 0 THEN
            STOP the loop
        END IF
        IF choice < 1 OR choice > 13 THEN
            PRINT "Invalid food ID"
            GO BACK to start of loop
        END IF
        INPUT quantity
        IF quantity <= 0 THEN
            PRINT "Invalid quantity"
            GO BACK to start of loop
        END IF
        menu[choice].quantity = menu[choice].quantity + quantity
        menu[choice].amount   = menu[choice].price * menu[choice].quantity
        PRINT "Item added successfully"
    END REPEAT
END FUNCTION


FUNCTION calculateBill(bill)
    SET bill.total = 0
    FOR i = 1 TO 13
        bill.total = bill.total + menu[i].amount
    END FOR
    IF bill.total >= 500 THEN
        bill.discount = 10% of bill.total
    ELSE
        bill.discount = 0
    END IF
    bill.finalAmount = bill.total - bill.discount
END FUNCTION

FUNCTION paymentMethod(bill)
    PRINT "1. Cash  2. UPI  3. Card"
    INPUT bill.payment
    IF bill.payment < 1 OR bill.payment > 3 THEN
        PRINT "Invalid choice, using Cash"
        bill.payment = 1
    END IF
END FUNCTION

FUNCTION generateBill(bill)
    PRINT receipt header and bill.orderNo
    FOR i = 1 TO 13
        IF menu[i].quantity > 0 THEN
            PRINT name, quantity, price, amount
        END IF
    END FOR
    PRINT bill.total, bill.discount, bill.finalAmount
    IF bill.payment = 1 THEN PRINT "Cash"
    ELSE IF bill.payment = 2 THEN PRINT "UPI"
    ELSE PRINT "Card"
    END IF
    PRINT "THANK YOU! VISIT AGAIN!"
END FUNCTION

FUNCTION salesReport()
    PRINT totalOrders
    PRINT totalSales
END FUNCTION

MAIN PROGRAM
    PRINT welcome message
    SET again = 1
    WHILE again = 1
        FOR i = 1 TO 13
            menu[i].quantity = 0
            menu[i].amount = 0
        END FOR
        bill.orderNo = totalOrders + 1
        CALL takeOrder()
        IF every menu[i].quantity is 0 THEN
            PRINT "No items ordered"
        ELSE
            CALL calculateBill(bill)
            CALL paymentMethod(bill)
            CALL generateBill(bill)
            totalOrders = totalOrders + 1
            totalSales  = totalSales + bill.finalAmount
        END IF
        PRINT "Serve another customer? 1 = Yes, 0 = No"
        INPUT again
    END WHILE
    CALL salesReport()
    PRINT "Canteen Closed. Have a Nice Day!"
END
