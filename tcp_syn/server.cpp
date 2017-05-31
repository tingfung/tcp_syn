#include <boost/asio.hpp>
#include <iostream>
using namespace boost::asio;
using namespace std;


int main()
try
{
	typedef ip::tcp::acceptor	acceptor_type;  //�����Ͷ���
	typedef ip::tcp::endpoint	endpoint_type;
	typedef ip::tcp::socket		socket_type;

	cout << "server start." << endl;
	io_service io;

	acceptor_type acceptor(io,						//����acceptor����ipv4
		endpoint_type(ip::tcp::v4(), 6688));		//����6688�˿ڣ���ʼ����
	cout << acceptor.local_endpoint().address() << endl;

	for (;;)														//ѭ��ִ������
	{
		socket_type sock(io);								//һ��sock����
		acceptor.accept(sock);							//�����ȴ�socket����

		cout << "client:";
		cout << sock.remote_endpoint().address() << endl;

		sock.send(buffer("hello asio"));				//�������ݣ�ʹ��buffer()
	}
}
catch (const std::exception& e)						//������ܷ������쳣
{
	cout << e.what() << endl;
}