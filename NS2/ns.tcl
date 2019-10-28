set ns [new Simulator]

$ns color 1 Green
$ns color 2 Red

set nf [open out.nam w]
$ns namtrace-all $nf

set tr4 [open trace.tr w]
$ns trace-all $tr4

proc finish {} {
	global ns nf
	$ns flush-trace
	close $nf
	exec nam out.nam &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

$ns duplex-link $n0 $n1 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 1.7Mb 10ms DropTail
$ns queue-limit $n1 $n2 7

$ns duplex-link-op $n0 $n1 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up

$ns duplex-link-op $n1 $n2 queuePos 0.4

set tcp [new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink
$ns connect $tcp $sink
$tcp set fid_ 1

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

$ns at 0.1 "$ftp start"
$ns at 4.0 "$ftp stop"

$ns at 4.5 "finish"

$ns run