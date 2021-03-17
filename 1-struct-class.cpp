#include <stdio.h>
#include <string.h>

/* C-like struktura
 */
struct my_struct_t {
    // vzdycky public
    int type;
    char name[64];

    // struktura muze mit konstruktor
    my_struct_t() {

    }

    // konstruktor muzeme pretezovat
    my_struct_t(int t, const char* n) {
        type = t;
        strcpy_s(name, n);
    }
};

void my_set_type(my_struct_t* s, int type) {
    if (s == NULL) return;

    s->type = type;
}

int my_get_type(my_struct_t* s) {
    if (s == NULL) return -1;
    return s->type;
}

void my_set_name(my_struct_t* s, const char* name) {
    if (s == NULL) return;
    memset(s->name, 0, sizeof(strlen(s->name) * sizeof(char)));
    strcpy_s(s->name, name);
}

const char* my_get_name(my_struct_t* s) {
    if (s == NULL) return NULL;
    return s->name;
}

void my_printf_info(my_struct_t* s) {
    if (s == NULL) return;
    printf("type: %d\n", s->type);
    printf("name: %s\n", s->name);
}

/*
 */
class my_class_t {

    // private prvky
    int type;
    char name[64];

    // public prvky
public:
    // konstruktor
    my_class_t() {

    }

    my_class_t(int type, const char* name) {
        this->type = type;
        strcpy_s(this->name, name);
    }

    // destruktor
    ~my_class_t() {

    }

    void setType(int type) {
        this->type = type;
    }

    int getType() {
        return this->type;
    }

    void setName(const char* name) {
        strcpy_s(this->name, name);
    }

    const char* getName() {
        return this->name;
    }

    void printInfo() {
        printf("type: %d\n", this->type);
        printf("name: %s\n", this->name);
    }
};

/*
 */
int main() {

    // volani bez uziti konstruktoru
    my_struct_t static_struct;
    static_struct.type = 1;
    strcpy_s(static_struct.name, "Ondrej");
    printf("my_struct_t:\ttype: %d\tname: %s\n", static_struct.type, static_struct.name);
printf("where i am: %d %s\n", __LINE__, __FILE__);
    // pomoci funkci
    my_set_type(&static_struct, 5);
    my_printf_info(&static_struct);

    my_set_name(&static_struct, "Tomas");
    my_printf_info(&static_struct);

    // volani s uzitim konstruktoru
    my_struct_t static_struct_1(1, "Michal");
    my_printf_info(&static_struct_1);
 printf("where i am: %d %s\n", __LINE__, __FILE__);
    // class
    my_class_t static_class;
    static_class.setType(1);
    static_class.setName("Samuel");
    // neni povoleno kvuli private pristupu
    //printf("my_struct_t:\ttype: %d\tname: %s\n", static_class.type, static_class.name);
    printf("my_struct_t:\ttype: %d\tname: %s\n", static_class.getType(), static_class.getName());
    static_class.printInfo();

    // volani s uzitim konstruktoru
    my_class_t static_class_1(5, "Ivo");
    static_class_1.printInfo();
 printf("where i am: %d %s\n", __LINE__, __FILE__);

    return 0;
}