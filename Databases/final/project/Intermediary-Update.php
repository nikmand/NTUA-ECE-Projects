	<?php	
		$con = mysqli_connect("localhost:3306","root","","project");
		if (mysqli_connect_errno())
		{
			die('Could not connect: ' . mysqli_error($con));
		}

		$MId=$_GET['MId'];
		$Name=$_GET['Name'];
		$Town=$_GET['Town'];
		$StreetName=$_GET['StreetName'];
		$StreetNumber=$_GET['StreetNumber'];
		$PoastalCode=$_GET['PoastalCode'];
		if ($MId==='' or $Name==='' or $Town==='' or $StreetName==='' or $StreetNumber==='' or $PoastalCode===''){
			header('Location:Intermediary-Update.html');
			exit;
		}
		
		$result = mysqli_query($con, "UPDATE intermediary SET Name='$Name', Town='$Town', StreetName='$StreetName', StreetNumber=$StreetNumber, PoastalCode=$PoastalCode 
		WHERE MId=$MId");
		
		if($result === FALSE) { 
			die(mysqli_error($con)); 
		}
		mysqli_close($con);
		
	?>	
	
<html style="background-color:#f8f0e2;">
<head>
	<title>Redirecting</title>
</head>
<body>
		<meta http-equiv="refresh" content="2; url=main.html" />
		<h1 align="center" style="color:darkred;font-size=200px;font-family:Lucida Handwriting;"><strong>Redirecting you in 3 seconds...</strong></h1>
</body>
</html>