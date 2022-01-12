class PhysicalEntity {

struct collisionner {
    Entity* touching;
    Entity* touched;
    std::vector<int> intricate;
};

typedef struct collisionner collisionner;

static void correctionUpdate(std::vector<collisionner> collisionners)
{
    for (collisionner col : collisionners) {
        Entity ett1 = *col.touching;
        Entity ett2 = *col.touched;
        std::vector<int> intr = col.intricate;
        unsigned float m1,m2; //mass
        //TODO implement bouncyness later
        // unsigned double b1,b2; //bouncyness
        // b1 = ett1.bouncyness;
        // b2 = ett2.bouncyness;
        m1 = ett1.mass;
        m2 = ett2.mass;
        const unsigned float ratio = m2/(m1 + m2);
        // Inherited from SFML transformable
        ett1.move(floor( ratio     *intr[0]),floor( ratio     *intr[1]));
        ett2.move(floor((ratio - 1)*intr[0]),floor((ratio - 1)*intr[1]));
    }
}
}