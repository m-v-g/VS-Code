#pragma once //kopilyator@ chi tuyl ta es fayl@ 1-ic avel angam includ enenq

#include <iostream>
//#include <string> 
#include <sstream>

class IndexOutOfBounds
{
    public:
        std::string prichina;
        std::string reshenie;
        int index;
        time_t kogda; //time_t tipi popoxakan vori mej kphenq 01.01.1970-ic mincev hmi varkyanneri qanak@

        IndexOutOfBounds(std::string prichina, std::string reshenie, int index, time_t kogda)
        {
            this->prichina = prichina; //"this->patchar" global membern e isk "patchar" stex stexcvac popoxakann e
            this->reshenie = reshenie; //knshanake es obekti member@ = es obektum stexcvac popoxakanin
            this->index = index;
            this->kogda = kogda;
        }

        void display()
        {
            std::cout << "-------------------------------------------" << std::endl;
            std::cout << "cause: " << prichina << std::endl;
            std::cout << "solution: " << reshenie << index << std::endl;
            std::cout << "when happened: " << ctime(&kogda) << std::endl;// ctime funkcia vor@ k@ndune erbi hascen u het
                                                               // kveradardzne normal formati berac amis amsativ@
            std::cout << "-------------------------------------------" << std::endl;
        } 
};


class Income
{
    public:
        double fromStore;
        double fromTender;
        double fromInstalation;
        double fromCashBack;
        double fromService;

    
        Income(){} //konstruktor bez argumentov

        Income(Income& other) //konstruktor kopirovaniya
        {
            this->fromStore = other.fromStore;
            this->fromTender = other.fromTender;
            this->fromInstalation = other.fromInstalation;
            this->fromCashBack = other.fromCashBack;
            this->fromService = other.fromService;
        }

        Income(double st, double te, double in, double ca, double se)
        {
            fromStore = st;
            fromTender = te;
            fromInstalation = in;
            fromCashBack = ca;
            fromService = se;
        }

        float total(const Income* other)
        {
            return other->fromStore + other->fromTender + other->fromCashBack + other->fromInstalation + other->fromService;
        }

        int compear(const Income temp1,const Income temp2)
        {
            if(total(&temp1) < total(&temp2)) return -1;
            else if(total(&temp1) > total(&temp2)) return 1;
            else return 0;
        }

        //k@ndune 2 argument 1-ostream/istream tesaki obekt 2-mer grats data type tesaki obekt
        //ete hech ban chveradadzne menq mi qani hat irar koxq cout chenq krna ene
        //@dur hamar el kveradadznenc mer sarqats ostrimi obekt@
        //by referance kenenq vorovhetev es tesaki obektneri kopyaner@ sarqel@ hesht ban che
        //friend funkcianer@ krnanq haytararenq klasic durs, iranq chen jarangvi, bayc iranq
        //dostup unin mer klasi private u protected dashterin
        friend std::ostream& operator<<(std::ostream& tpel, const Income obj)
        {
            std::cout << "==============" << std::endl;
            tpel << "From Store:\t" << obj.fromStore << std::endl;
            tpel << "From Tender:\t" << obj.fromTender << std::endl;
            tpel << "From Instal:\t" << obj.fromInstalation << std::endl;
            tpel << "From Cash Back:\t" << obj.fromCashBack << std::endl;
            tpel << "From Service:\t" << obj.fromService << std::endl;
            return tpel;
        }

        friend std::istream& operator>>(std::istream& nermucel, Income obj)
        {
            std::cout << "Insert From Store:\t";
            nermucel >> obj.fromStore;
            std::cout << "Insert From Tender:\t";
            nermucel >> obj.fromTender;
            std::cout << "Insert From Instal:\t";
            nermucel >> obj.fromInstalation;
            std::cout << "Insert From Cash Back:\t";
            nermucel >> obj.fromCashBack;
            std::cout << "Insert From Service:\t";
            nermucel >> obj.fromService;
            return nermucel;
        }

        Income& operator= (const Income other) //operator prisvoivoniya
        {
            this->fromStore = other.fromStore;
            this->fromTender = other.fromTender;
            this->fromInstalation = other.fromInstalation;
            this->fromCashBack = other.fromCashBack;
            this->fromService = other.fromService;
            return *this;
        }

        bool operator== (const Income& other) //operator sravneniya
        {
            if(this == &other) return true; //ete hamematum enq 2 nuyn obyektner@
            else if(this->fromStore != other.fromStore) return false;
            else if(this->fromTender != other.fromTender) return false;
            else if(this->fromInstalation != other.fromInstalation) return false;
            else if(this->fromCashBack != other.fromCashBack) return false;
            else if(this->fromService != other.fromService) return false;
            return true; //ete sqan ban@ ancel enq uremn havasar en
        }

        bool operator!= (Income& other)
        {
            int cmp = compear(*this, other);
            if(cmp == 0) return false;
            else return true;
        }

        bool operator< (Income& other)
        {
            int cmp = compear(*this, other);
            if(cmp < 0) return true;
            else return false;
        }

        bool operator> (Income& other)
        {
            int cmp = compear(*this, other);
            if(cmp > 0) return true;
            else return false;
        }

        bool operator<= (Income& other)
        {
            int cmp = compear(*this, other);
            if(cmp <= 0) return true;
            else return false;
        }

        bool operator>= (Income& other)
        {
            int cmp = compear(*this, other);
            if(cmp >= 0) return true;
            else return false;
        }

        const Income operator+ (const Income& other)
        {
            Income temp;
            temp.fromStore = this->fromStore + other.fromStore;
            temp.fromTender = this->fromTender + other.fromTender;
            temp.fromInstalation = this->fromInstalation + other.fromInstalation;
            temp.fromCashBack = this->fromCashBack + other.fromCashBack;
            temp.fromService = this->fromService + other.fromService;
            return temp;
        }

        const Income operator- (const Income& other)
        {
            Income temp;
            temp.fromStore = this->fromStore - other.fromStore;
            temp.fromTender = this->fromTender - other.fromTender;
            temp.fromInstalation = this->fromInstalation - other.fromInstalation;
            temp.fromCashBack = this->fromCashBack - other.fromCashBack;
            temp.fromService = this->fromService - other.fromService;
            return temp;
        }

         const Income operator* (const Income& other)
        {
            Income temp;
            temp.fromStore = this->fromStore * other.fromStore;
            temp.fromTender = this->fromTender * other.fromTender;
            temp.fromInstalation = this->fromInstalation * other.fromInstalation;
            temp.fromCashBack = this->fromCashBack * other.fromCashBack;
            temp.fromService = this->fromService * other.fromService;
            return temp;
        }

         const Income operator/ (const Income& other)
        {
            Income temp;
            temp.fromStore = this->fromStore / other.fromStore;
            temp.fromTender = this->fromTender / other.fromTender;
            temp.fromInstalation = this->fromInstalation / other.fromInstalation;
            temp.fromCashBack = this->fromCashBack / other.fromCashBack;
            temp.fromService = this->fromService / other.fromService;
            return temp;
        }

        const Income& operator+= (const Income& other)
        {
            this->fromStore += other.fromStore;
            this->fromTender += other.fromTender;
            this->fromInstalation += other.fromInstalation;
            this->fromCashBack += other.fromCashBack;
            this->fromService += other.fromService;
            return *this;
        }

        const Income& operator-= (const Income& other)
        {
            this->fromStore -= other.fromStore;
            this->fromTender -= other.fromTender;
            this->fromInstalation -= other.fromInstalation;
            this->fromCashBack -= other.fromCashBack;
            this->fromService -= other.fromService;
            return *this;
        }

         const Income& operator*= (const Income& other)
        {
            this->fromStore *= other.fromStore;
            this->fromTender *= other.fromTender;
            this->fromInstalation *= other.fromInstalation;
            this->fromCashBack *= other.fromCashBack;
            this->fromService *= other.fromService;
            return *this;
        }

         const Income& operator/= (const Income& other)
        {
            this->fromStore /= other.fromStore;
            this->fromTender /= other.fromTender;
            this->fromInstalation /= other.fromInstalation;
            this->fromCashBack /= other.fromCashBack;
            this->fromService /= other.fromService;
            return *this;
        }

        const Income& operator++ () //prefix increment
        {
            this->fromStore++;
            this->fromTender++;
            this->fromInstalation++;
            this->fromCashBack++;
            this->fromService++;
            return *this;
        }

        const Income operator++ (int tmp) //postfix increment
        {
            Income temp = *this;
            this->fromStore++;
            this->fromTender++;
            this->fromInstalation++;
            this->fromCashBack++;
            this->fromService++;
            return temp;
        }

        const Income& operator-- () //prefix decrement
        {
            this->fromStore--;
            this->fromTender--;
            this->fromInstalation--;
            this->fromCashBack--;
            this->fromService--;
            return *this;
        }

        const Income operator-- (int tmp) //postfix decrement
        {
            Income temp = *this;
            this->fromStore--;
            this->fromTender--;
            this->fromInstalation--;
            this->fromCashBack--;
            this->fromService--;
            return temp;
        }

        operator bool() //operator preobrazovaniya tipa v bool
        {
            return total(this);
        }

        operator int() //operator preobrazovaniya tipa v int
        {
            return total(this);
        }

        operator float() //operator preobrazovaniya tipa v float
        {
            return total(this);
        }

        operator double() //operator preobrazovaniya tipa v double
        {
            return total(this);
        }

        operator char() //operator preobrazovaniya tipa v char
        {
            return (char)total(this);
        }

        std::string toString()
        {
            std::ostringstream oss;
            oss<< total(this);
            return oss.str();
        }

        double& operator[](int index) //operator indexirovaniya
        {
            switch (index)
            {
            case 0:
                return this->fromStore;
                break;

            case 1:
                return this->fromTender;
                break;

            case 2:
                return this->fromInstalation;
                break;
            
            case 3:
                return this->fromCashBack;
                break;

            case 4:
                return this->fromService;
                break;   

            default:
                IndexOutOfBounds ex("Inserted wrong index", "Insert index between 0 - ", 4, time(0));
                throw ex;
                break;
            }
            throw 200; //zaglushka e or return chgrenq
        }
};