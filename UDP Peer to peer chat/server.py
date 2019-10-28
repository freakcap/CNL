import os
import sys
import socket
import threading

class Server:
	def create(self):
		self.port = 25000
		self.sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
		self.sock.bind(('',self.port))
		print("Socket binded successfuly to port : "+str(self.port))
		self.chatWindow()
		return

	def chatWindow(self):
		os.system("clear")
		print("Chat Messenger Server : \n")
		threadS = threading.Thread(target = self.sender)
		threadR = threading.Thread(target = self.receiver)

		threadS.start()
		threadR.start()

	def sender(self):
		while True:
			msg = bytes(input(),"utf-8")
			self.sock.sendto(msg,self.addr)
			if(msg.decode("utf-8").strip() == "bye"):
				self.sock.close()
				print("Closing connection")
				#os.system("init 0")
				return

	def receiver(self):
		while True:
			msg , self.addr = self.sock.recvfrom(1024)
			print("Message from "+str(self.addr)+" : "+str(msg.decode("utf-8")))
			

if __name__ == '__main__':
	server = Server()
	server.create()

