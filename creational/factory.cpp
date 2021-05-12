#include <iostream>
#include <memory>

/*usb, serial, bluetooth, wifi*/
class usb;
class Serial;
class BlueTooth;
class WiFi;

//base class
class F_Connection{
    public:
        virtual ~F_Connection()         = default;
        virtual uint32_t f_connect()    = 0;
        virtual uint32_t f_disconnect() = 0;
        virtual uint32_t f_sendMsg(std::string msg)    = 0;
};

class usb : public F_Connection{
    public:
        usb()  { std::cout << "usb "  << std::endl; }
        ~usb() { std::cout << "~usb " << std::endl; }
        uint32_t f_connect()
        {
        std::cout << "USB connected" << std::endl;  
        return 0;  
        }

        uint32_t f_disconnect()
        {
        std::cout << "USB disconnect" << std::endl;  
        return 0;  
        }

        uint32_t f_sendMsg(std::string msg)
        {
        std::cout << "USB msg: " << msg << std::endl;  
        return 0;  
        }
};

class Serial : public F_Connection{
    public:
        Serial()  { std::cout << "serial "  << std::endl; }
        ~Serial() { std::cout << "~serial " << std::endl; }
        uint32_t f_connect()
        {
        std::cout << "Serial connected" << std::endl;  
        return 0;  
        }

        uint32_t f_disconnect()
        {
        std::cout << "Serial disconnect" << std::endl;  
        return 0;  
        }

        uint32_t f_sendMsg(std::string msg)
        {
        std::cout << "Serial msg: " << msg << std::endl;  
        return 0;  
        }

        //add more specific stuff like baudrate setup etc.
};

class Bluetooth : public F_Connection{
    public:
         Bluetooth()  { std::cout << "bluetooth "  << std::endl; }
        ~Bluetooth()  { std::cout << "~bluetooth " << std::endl; }

        uint32_t f_connect()
        {
        std::cout << "Bluetooth connected" << std::endl;  
        return 0;  
        }

        uint32_t f_disconnect()
        {
        std::cout << "Bluetooth disconnect" << std::endl;  
        return 0;  
        }

        uint32_t f_sendMsg(std::string msg)
        {
        std::cout << "Bluetooth msg: " << msg << std::endl;  
        return 0;  
        }
        //add more specific methods like APIs
};

class WiFi : public F_Connection{
    public:
        WiFi()   { std::cout << "wifi "  << std::endl; }
        ~WiFi()  { std::cout << "~wifi " << std::endl; }

        uint32_t f_connect()
        {
        std::cout << "WiFi connected" << std::endl;  
        return 0;  
        }

        uint32_t f_disconnect()
        {
        std::cout << "WiFi disconnect" << std::endl;  
        return 0;  
        }

        uint32_t f_sendMsg(std::string msg)
        {
        std::cout << "WiFi msg: " << msg << std::endl;  
        return 0;  
        }
        //add more WiFi specific methods like APIs, REST values etc
};

//factory will be used at the other end to access all this
//services as factory methods
class ConnectionFactory{
    public:
        enum ConnectionProtocol
        {
            USB = 0,
            SERIAL,
            BLUETOOTH,
            WIFI
        };

        std::unique_ptr<F_Connection> getConnection(ConnectionFactory::ConnectionProtocol protocol)
        {
            switch (protocol)
            {
            case ConnectionFactory::USB:
                return std::make_unique<usb>();
            case ConnectionFactory::SERIAL:
                return std::make_unique<Serial>();
            case ConnectionFactory::BLUETOOTH:
                return std::make_unique<Bluetooth>();
            case ConnectionFactory::WIFI:
                return std::make_unique<WiFi>();
            default:
                std::cout << "[E] protocol not supported" << std::endl;
                break;
            }
            return nullptr;//just because of gcc
        }
};

int main()
{
    auto connFactory = new ConnectionFactory();
    auto bt = connFactory->getConnection(ConnectionFactory::ConnectionProtocol::BLUETOOTH);
    bt->f_connect();
    bt->f_sendMsg("bluetooth connected");
    bt->f_disconnect();
    auto usb = connFactory->getConnection(ConnectionFactory::ConnectionProtocol::USB);
    usb->f_connect();
    usb->f_sendMsg("usb connected");
    usb->f_disconnect();
    auto serial = connFactory->getConnection(ConnectionFactory::ConnectionProtocol::SERIAL);
    serial->f_connect();
    serial->f_sendMsg("serial connected");
    serial->f_disconnect();
    auto wifi = connFactory->getConnection(ConnectionFactory::ConnectionProtocol::WIFI);
    wifi->f_connect();
    wifi->f_sendMsg("WiFi connected");
    wifi->f_disconnect();

    return 0;
}

