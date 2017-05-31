#include <boost/asio.hpp>
#include <iostream>
using namespace boost::asio;
using namespace std;


int main()
try
{
	typedef ip::address			address_type;  //�����Ͷ���
	typedef ip::tcp::endpoint	endpoint_type;
	typedef ip::tcp::socket		socket_type;

	cout << "client start." << endl;
	io_service io;												//io_service����
	socket_type sock(io);
	endpoint_type ep(										//�������Ӷ˵�
		address_type::from_string("127.0.0.1"), 6688);
	
	sock.connect(ep);										//socket���ӵ��˵�
	cout << sock.available() << endl;				//��ȡ�ɶ�ȡ���ֽ���

	vector<char> str(sock.available() + 1, 0);	//����һ��vector������
	sock.receive(buffer(str));							//ʹ��buffer()��װ�������Ľ�������
	cout << "receive from" << sock.remote_endpoint().address();
	cout << str[0] << endl;							//������յ����ַ���

	//���ֶ�ȡ��ʽ
	//vector<char> str(5, 0);								//����������5
	//error_code ec;											//������
	//for (;;)
	//{
	//	sock.read_some(buffer(str), ec);
	//	if (ec)
	//	{	break;	}
	//	cout << &str[0];
	//}
}
catch (const std::exception& e)						//������ܷ������쳣
{
	cout << e.what() << endl;
}