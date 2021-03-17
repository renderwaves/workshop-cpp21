#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* parent class
 */
class Object {

        int m_color[3];
        int m_type;        
        int m_size;
        int m_x;
        int m_y;

    public:

        enum Type_e {
            NONE = 0,
            RECTANGLE,
            CIRCLE,
            ELIPSE,
            NUM_TYPES,
        };

        // inicializacni konstruktor
        Object() {
            m_type = 0;
            m_size = 0;
            m_x = 0;
            m_y = 0;
            m_color[0] = m_color[1] = m_color[2] = 255;
        }

        // pretezovani konstruktoru
        Object(int type) : Object() {
            m_type = type;
        }

        Object(int type, int size) : Object(type) {
            m_size = size;
        }

        Object(int type, int x, int y) : Object(type) {
            m_x = x;
            m_y = y;            
        }

        Object(int type, int size, int x, int y) : Object(type, size) {
            m_x = x;
            m_y = y;
        }

        Object(Object *copy) {
            if (copy == NULL) return;
            m_type = copy->getType();
            m_size = copy->getSize();
            m_x = copy->m_x;
            m_y = copy->m_y;
            m_color[0] = copy->m_color[0];
            m_color[1] = copy->m_color[1];
            m_color[2] = copy->m_color[2];
        }

        virtual ~Object() {

        }

        int getType() {
            return m_type;
        }

        const char *getTypeName() {
            const char *ret;
            switch(m_type) {
                case NONE: ret = "None"; break;
                case RECTANGLE: ret = "Rectangle"; break;
                case CIRCLE: ret = "Circle"; break;
                case ELIPSE: ret = "Elipse"; break;
                default:
                    ret = "Unknown type!";
                    break;
            }
            return ret;
        }

        void setSize(int size) {
            m_size = size;
        }

        int getSize() {
            return m_size;
        }

        void setPosition(int x, int y) {
            m_x = x;
            m_y = y;
        }

        int getX() {
            return m_x;
        }

        int getY() {
            return m_y;
        }

        void setColor(int *color) {
            m_color[0] = color[0];
            m_color[1] = color[1];
            m_color[2] = color[2];
        }

        // pretezovani setColor
        void setColor(int r, int g, int b) {
            m_color[0] = r;
            m_color[1] = g;
            m_color[2] = b;
        }

        int *getColor() {
            return m_color;
        }

        virtual void render() {

        }
};

/* child class : Object
 */
class Rectangle : public Object {
    public:

        Rectangle() : Object(RECTANGLE) {
        }

        Rectangle(int x, int y) : Object(RECTANGLE, x, y) {
        }



        ~Rectangle() {

        }
};

/*
 */
class Circle : public Object {
    public:
        Circle() : Object(CIRCLE) {

        }

        ~Circle() {

        }

        virtual void render() {

        }
};

/*
 */
class Elipse : public Object {
    public:
        Elipse() : Object(ELIPSE) {

        }

        ~Elipse() {

        }

        virtual void render() {

        }
};

/* Tato trida bude neznamy typ
 */
class Hexagon : public Object {
    public:
        Hexagon() : Object() {

        }

        ~Hexagon() {

        }

        virtual void render() {

        }
};

/*
 */
void printObjectInfo(Object *object) {
    if (object == NULL) return;
    int *color = object->getColor();
    printf("printObjectInfo():\n\ttype: %d\n\ttypename: %s\n\tsize: %d\n\tx: %d\ty: %d\n\tr: %d\tg: %d\tb: %d\n", object->getType(), object->getTypeName(),object->getSize(), object->getX(), object->getY(), color[0], color[1], color[2]);
}

/*
 */
int main() {

    srand(time(NULL)); // inicializace random number generatoru

    Object *primitives[6];

    // inicializace
    for (int i = 0; i < sizeof(primitives)/sizeof(*primitives); i++) {

        // nahodne prirazeni potomka do pole primitivnich objektu
        int random_type = (rand() % (0 - Object::NUM_TYPES) + 0);
        switch(random_type) {
            default: primitives[i] = new Object(); break;
            case Object::CIRCLE: primitives[i] = new Circle(); break;
            case Object::ELIPSE: primitives[i] = new Elipse(); break;
            case Object::RECTANGLE: primitives[i] = new Rectangle(); break;
        }
        
        int color[3] = { 244, 53 , 22};
        primitives[i]->setColor(color);
    }

    // vypis vsechno
    for (int i = 0; i < sizeof(primitives) / sizeof(*primitives); i++) {
        printObjectInfo(primitives[i]);
    }
    
    // bezpecne odstraneni z pameti 
    for (int i = 0; i < sizeof(primitives)/sizeof(*primitives); i++) {
        delete primitives[i];
        primitives[i] = nullptr;        
    }

    return 0;
}