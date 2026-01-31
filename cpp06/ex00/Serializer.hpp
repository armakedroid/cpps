class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
        Serializer();
        Serializer& operator=(Serializer &other);
        Serializer(Serializer &other);
        ~Serializer();
};