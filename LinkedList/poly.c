// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// struct node{
//     float coef;
//     int expo;
//     struct node *next;
// };

// typedef struct node *NODE;

// NODE insert(NODE start, float co, int ex){
//     NODE ptr,temp;
//     temp=(NODE)malloc(sizeof(NODE));
//     temp->coef = co;
//     temp->expo = ex;
//     //list empty or exp greater than first one
//     if(start==NULL || ex>start->expo){
//         temp->next  = start;
//         start = temp;

//     }
//     else{
//         ptr = start;
//         while(ptr->next!=NULL && ptr->next->expo>ex)
//             ptr = ptr->next;
//         temp->next = ptr->next;
//         ptr->next =temp;
//         if(ptr->next == NULL)
//             temp->next = NULL; 
//     }
//     return start;
// }

// NODE polyadd(NODE p1, NODE p2){

// }
// int main(void)
// {

// return 0;
// }

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a single term of a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Structure to represent a polynomial
struct Polynomial {
    struct Term* head;
};

// Function to create a new term
struct Term* createTerm(int coef, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coef;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term into a polynomial
void insertTerm(struct Polynomial* poly, int coef, int exp) {
    struct Term* newTerm = createTerm(coef, exp);
    if (poly->head == NULL) {
        poly->head = newTerm;
    } else {
        struct Term* current = poly->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to add two polynomials and store the result in a third polynomial
struct Polynomial addPolynomials(struct Polynomial poly1, struct Polynomial poly2) {
    struct Polynomial result;
    result.head = NULL;

    struct Term* term1 = poly1.head;
    struct Term* term2 = poly2.head;

    while (term1 != NULL && term2 != NULL) {
        if (term1->exponent == term2->exponent) {
            insertTerm(&result, term1->coefficient + term2->coefficient, term1->exponent);
            term1 = term1->next;
            term2 = term2->next;
        } else if (term1->exponent > term2->exponent) {
            insertTerm(&result, term1->coefficient, term1->exponent);
            term1 = term1->next;
        } else {
            insertTerm(&result, term2->coefficient, term2->exponent);
            term2 = term2->next;
        }
    }

    while (term1 != NULL) {
        insertTerm(&result, term1->coefficient, term1->exponent);
        term1 = term1->next;
    }

    while (term2 != NULL) {
        insertTerm(&result, term2->coefficient, term2->exponent);
        term2 = term2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Polynomial poly) {
    struct Term* current = poly.head;
    while (current != NULL) {
        printf("%dx^%d ", current->coefficient, current->exponent);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Polynomial poly1, poly2, result;

    poly1.head = NULL;
    poly2.head = NULL;

    // Insert terms into the first polynomial (3x^2 + 2x^1 + 5x^0)
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 2, 1);
    insertTerm(&poly1, 5, 0);

    // Insert terms into the second polynomial (4x^3 + 3x^2 + 1x^0)
    insertTerm(&poly2, 4, 3);
    insertTerm(&poly2, 3, 2);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Sum: ");
    displayPolynomial(result);

    return 0;
}
