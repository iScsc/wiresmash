class PhysicalEntity {

struct collisionner {
    Entity* touched;
    Entity* touching;
    std::vector<int> intricate;
};

typedef struct collisionner collisionner;

static void correctionUpdate(std::vector<collisionner> collisionners)
{
    for (collisionner col : collisionners) {
        Entity ett1 = *col.touched;
        Entity ett2 = *col.touching;
        std::vector<int> intr = col.intricate;
        unsigned double m1,m2; //mass
        // unsigned double b1,b2; //bouncyness
        // b1 = ett1.bouncyness;
        // b2 = ett2.bouncyness;
        m1 = ett1.mass;
        m2 = ett2.mass;
        unsigned double ratio = m1/(m1+m2);
        ett1.translate(-ratio*intr);
        ett2.translate((1-ratio)*intr);
    }
}
}