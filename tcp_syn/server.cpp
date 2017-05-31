#include <boost/asio.hpp>
#include <iostream>
using namespace boost::asio;
using namespace std;


int main()
try
{
	typedef ip::tcp::acceptor	acceptor_type;  //简化类型定义
	typedef ip::tcp::endpoint	endpoint_type;
	typedef ip::tcp::socket		socket_type;

	cout << "server start." << endl;
	io_service io;

	acceptor_type acceptor(io,						//创建acceptor对象，ipv4
		endpoint_type(ip::tcp::v4(), 6688));		//接受6688端口，开始侦听
	cout << acceptor.local_endpoint().address() << endl;

	for (;;)														//循环执行任务
	{
		socket_type sock(io);								//一个sock对象
		acceptor.accept(sock);							//阻塞等待socket连接

		cout << "client:";
		cout << sock.remote_endpoint().address() << endl;

		sock.send(buffer("hello asio"));				//发送数据，使用buffer()
	}
}
catch (const std::exception& e)						//捕获可能发生的异常
{
	cout << e.what() << endl;
}