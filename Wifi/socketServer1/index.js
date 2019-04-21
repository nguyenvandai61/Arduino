const PORT = 8888;								//Đặt địa chỉ Port được mở ra để tạo ra chương trình mạng Socket Server
var ip = require('ip');
var app = require('express')();
var http = require('http').Server(app);//#Khởi tạo một chương trình mạng (app)
var io = require('socket.io')(http);//#Phải khởi tạo io sau khi tạo app!
var bodyparser = require('body-parser');

app.use(bodyparser.urlencoded({extended: true}));
app.use(bodyparser.json());
app.get('/', function (req, res) {
	res.sendfile('main.html');
});


http.listen(PORT, function () {
	console.log("Server nodejs chay tai dia chi: " + ip.address() + ":" + PORT)
});



function getLedControl() {
	app.post('/', (req, res)=>{
		console.log(req.body);
		var val = parseInt(req.body.value)
		io.sockets.emit('OnOrOff', val);
	});
}

//Khi có mệt kết nối được tạo giữa Socket Client và Socket Server
io.on('connection', function (socket) {
	console.log("Connected"); //In ra màn hình console là đã có một Socket Client kết nối thành công.

	socket.on('connection', function (message) {
		console.log(message);
	});
	// //khi lắng nghe được lệnh "atime" với một tham số, và chúng ta đặt tên tham số đó là data. Mình thích thì mình đặt thôi
	socket.on('OnOrOff', function (data) {
		getLedControl();
		console.log(data);
	});

	socket.on('TurnedOn', function(message){
		console.log(message);
	});
	socket.on('TurnedOff', function(message){
		console.log(message);
	});
});