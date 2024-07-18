#include "function.h"

void input(char attrib[], char* elem_contact) {
    printf("%s: ", attrib);
    if (fgets(elem_contact, MAX_LEN, stdin) == NULL) error("INCORRECT LENGHT");
}

unsigned int input_arr(char attrib[]) {
    printf("%s: ", attrib);
    unsigned int num = 0;
    if (scanf("%d", &num) != 1) {
        return num;
    }
    getchar();
    if (num >= MAX_LEN) error("INCORRECT NUMBER");
    return num;
}

void addContact(struct Contacts* contacts) {
    struct Contact* contact = (struct Contact*)malloc(sizeof(struct Contact));

    input("firstName", contact->firstname);
    if (!strcmp(contact->firstname, "\n")) {
        error("REQUIRED VALUE");
    }

    input("lastname", contact->lastname);
    if (!strcmp(contact->lastname, "\n")) {
        error("REQUIRED VALUE");
    }

    input("jobname", contact->jobname);

    unsigned int num = input_arr("number of phone");
    if (num) {       
        for (struct Phone* phone; num != 0;) {
            phone=(struct Phone*)malloc(sizeof(struct Phone));
            input("phonename",phone->phonename);
            input("phone", phone->phone);

            contact->phone[--num]=phone;
        }
    }

    num = input_arr("number of email");
    if (num) {       
        for (struct Email* email; num != 0;) {
            email=(struct Email*)malloc(sizeof(struct Email));
            input("email", email->email);

            contact->email[--num]=email;
        }
    }

    num = input_arr("number of linkmessage");
    if (num) {       
        for (struct LinkMessage* link; num != 0;) {
            link=(struct LinkMessage*)malloc(sizeof(struct LinkMessage));
            input("linkmessage", link->linkmessage);

            contact->linkmessage[--num]=link;
        }
    }

    contacts->contact[keygen(contact->firstname, contact->lastname)] = contact;
}

void delContact(struct Contacts* contacts) {
    char firstname[MAX_LEN];
    char lastname[MAX_LEN];

    input("firstName", firstname);
    input("lastname", lastname);

    unsigned int index = keygen(firstname, lastname);

    if ( contacts->contact[index] != NULL ) {
        free(contacts->contact[index]);
        contacts->contact[index] = NULL;
        printf("\033[0;32mSUCCESS\033[0m\n");
    } 
    else printf("\033[0;31mNOT FOUND\033[0m\n");
}

void listContact(struct Contacts* contacts) {
    for (int i = 0; i < MAX_LEN_CONTACT; i++) {
        if (contacts->contact[i]) {
            printf("------------------------\n");
            printf("firstName: %s", contacts->contact[i]->firstname);
            printf("lastName: %s", contacts->contact[i]->lastname);
            printf("jobName: %s", contacts->contact[i]->jobname);

            for (int j = 0; contacts->contact[i]->phone[j] != NULL; j++) {
                printf("phone num %d:\n\tphonename: %s\tphone: %s", j + 1, contacts->contact[i]->phone[j]->phonename, contacts->contact[i]->phone[j]->phone);
            }
            for (int j = 0; contacts->contact[i]->email[j] != NULL; j++) {
                printf("email num %d:\n\tphone: %s", j + 1, contacts->contact[i]->email[j]->email);
            }
            for (int j = 0; contacts->contact[i]->linkmessage[j] != NULL; j++) {
                printf("linkmessage num %d:\n\tlinkmessage: %s", j + 1, contacts->contact[i]->linkmessage[j]->linkmessage);
            }
        }
    }
}