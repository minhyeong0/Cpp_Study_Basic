#include <iostream>

using namespace std;

class USBDevice
{
private:
    long m_id;

public:
    USBDevice(long id) :m_id(id) {}
    long getID() { return m_id; }
    void plugAndPlay() {}
};

class NetworkDevice
{
private:
    long m_id;

public:
    NetworkDevice(long id) :m_id(id) {}
    long getID() { return m_id; }
    void networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
    USBNetworkDevice(long usb_id, long net_id)
        :USBDevice(usb_id), NetworkDevice(net_id)
    {}

    
};

int main()
{
    USBNetworkDevice my_device(3.14, 6.022);
    my_device.networking();
    my_device.plugAndPlay();
    
    //다중상속 받을 때 이름이 중복되는 경우 클래스 이름 붙이기
    my_device.USBDevice::getID();
    my_device.NetworkDevice::getID();

    return 0;
}