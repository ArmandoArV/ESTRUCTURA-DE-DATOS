class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int numerator, int denominator);
        Fraction();
        ~Fraction();
        int getNumerator();
        int getDenominator();
        void setNumerator(int numerator);
        void setDenominator(int denominator);
        void reduce(int numerator, int denominator);
        void recursive_reduce(int numerator, int denominator);
};