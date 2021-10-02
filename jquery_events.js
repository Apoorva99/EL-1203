$("button").click(function(){
	var text = $(this).text();
	$(this).css({"background":"pink"});
	console.log("You clicked "+text);
	alert("you clicked "+text);
});
$("button").on("mouseenter",function(){
	$(this).css({"font-weight":"bold"});
});
$("button").on("mouseleave",function(){
	$(this).css({"font-weight":"normal"});
});
$("#clickme").click(function(){
	$(".faded").fadeOut("slow",function(){
		$("this").remove();
		$(".button1").css({
			"border":"2px solid black",
			"margin":"4px"
		});
		$(".button1").animate({top:'150px'});
		$("#clickme").fadeOut(1000);
	});
})