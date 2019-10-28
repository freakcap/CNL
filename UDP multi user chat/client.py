import os
import socket
import threading


class Client:
	def create(self):
		self.ip = "127.0.0.1"
		self.port = 25000
		self.sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

		print("Binded successfully..")
		self.sock.sendto(bytes('',"utf-8"),(self.ip,self.port))
		self.chatWindow()

	def chatWindow(self):
		os.system("clear")
		print("Chat Messenger client :\n")

		threadS = threading.Thread(target = self.sender)
		threadR = threading.Thread(target = self.receiver)
		threadS.start()
		threadR.start()

	def sender(self):
		while True:
			msg = bytes(input(),"utf-8")
			self.sock.sendto(msg,(self.ip,self.port))

	def receiver(self):
		while True:
			msg,addr = self.sock.recvfrom(1024)

			if("|||" in msg.decode("utf-8")):
				msg , addr = msg.decode("utf-8").split("|||");
				print("Message from "+str(addr)+": "+str(msg))
			else:
				print("Message from "+str(addr)+": "+str(msg.decode("utf-8")))

if __name__ == '__main__':
	client = Client()
	client.create()
