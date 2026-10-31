#include <stdio.h>

struct bus {
    char name[30];
    int age;
    char phone[15];
    int status;   // 1 = booked, 0 = empty
};

struct bus s[20];

void book() {
    int n;
    printf("Enter seat no (1-20): ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Wrong seat number\n");
        return;
    }

    if (s[n-1].status == 1) {
        printf("Seat already booked\n");
        return;
    }

    printf("Name: ");
    scanf(" %[^\n]", s[n-1].name);
    printf("Age: ");
    scanf("%d", &s[n-1].age);
    printf("Phone: ");
    scanf("%s", s[n-1].phone);

    s[n-1].status = 1;
    printf("Seat %d booked\n", n);
}

void cancel() {
    int n;
    printf("Enter seat no to cancel: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Wrong seat number\n");
        return;
    }

    if (s[n-1].status == 0) {
        printf("This seat is not booked\n");
    } else {
        s[n-1].status = 0;
        printf("Seat %d cancelled\n", n);
    }
}

void available() {
    int i;
    printf("Empty seats: ");
    for (i = 0; i < 20; i++) {
        if (s[i].status == 0)
            printf("%d ", i + 1);
    }
    printf("\n");
}

void details() {
    int i, c = 0;
    for (i = 0; i < 20; i++) {
        if (s[i].status == 1) {
            printf("\nSeat %d\n", i + 1);
            printf("Name: %s\n", s[i].name);
            printf("Age: %d\n", s[i].age);
            printf("Phone: %s\n", s[i].phone);
            c++;
        }
    }
    if (c == 0)
        printf("No bookings yet\n");
}

int main() {
    int ch;

    while (1) {
        printf("\n--- Bus Reservation ---\n");
        printf("1. Book seat\n");
        printf("2. Cancel seat\n");
        printf("3. Seat availability\n");
        printf("4. Passenger details\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            book();
        else if (ch == 2)
            cancel();
        else if (ch == 3)
            available();
        else if (ch == 4)
            details();
        else if (ch == 5)
            break;
        else
            printf("Invalid choice\n");
    }

    return 0;
}