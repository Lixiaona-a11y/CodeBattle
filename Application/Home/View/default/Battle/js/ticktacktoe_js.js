function init() {
    var canvas = document.getElementById('canvas');
    var context = canvas.getContext('2d');
    context.beginPath();
    context.lineWidth = '2';
    context.moveTo(70, 0);
    context.lineTo(70, 200);
    context.moveTo(140, 0);
    context.lineTo(140, 200);
    context.moveTo(0, 70);
    context.lineTo(200, 70);
    context.moveTo(0, 140);
    context.lineTo(200, 140);
    context.stroke();
}

function drawRound() {
    var canvas = document.getElementById('canvas');
    var context = canvas.getContext('2d');
    context.beginPath();
    context.arc(35, 35, 20, 0, Math.PI * 2, true);
    context.lineWidth = '3';
    context.strokeStyle = "black";
    context.stroke();
    context.closePath();
}
function drawX() {
    var canvas = document.getElementById('canvas');
    var context = canvas.getContext('2d');
    context.beginPath();
    context.lineWidth = '3';
    context.moveTo(90, 20);
    context.lineTo(120, 50);
    context.moveTo(120, 20);
    context.lineTo(90, 50);
    context.stroke();
}
//��ά���黭Բ
function drawRoundByLocation(x, y) {
    var canvas = document.getElementById('canvas');
    var context = canvas.getContext('2d');
    context.beginPath();
    context.arc(70 * y + 35, 70 * x + 35, 20, 0, Math.PI * 2, true);
    context.lineWidth = '3';
    context.strokeStyle = "black";
    context.stroke();
    context.closePath();
}
//һλ���黭Բ
function drawRoundByArr(x)
{
    switch(x)
    {
        case 0: drawRoundByLocation(0,0); break;
        case 1: drawRoundByLocation(0,1); break;
        case 2: drawRoundByLocation(0,2); break;
        case 3: drawRoundByLocation(1,0); break;
        case 4: drawRoundByLocation(1,1); break;
        case 5: drawRoundByLocation(1,2); break;
        case 6: drawRoundByLocation(2,0); break;
        case 7: drawRoundByLocation(2,1); break;
        case 8: drawRoundByLocation(2,2); break;
    }
}
//��ά���黭X
function drawXByLocation(x, y) {
    var canvas = document.getElementById('canvas');
    var context = canvas.getContext('2d');
    context.beginPath();
    context.lineWidth = '3';
    context.moveTo(70 * y + 20, 70 * x + 20);
    context.lineTo(70 * y + 50, 70 * x + 50);
    context.moveTo(70 * y + 50, 70 * x + 20);
    context.lineTo(70 * y + 20, 70 * x + 50);
    context.stroke();
}
//һά���黭X
function drawXByArr(x)
{
    switch(x)
    {
        case 0:drawXByLocation(0,0);break;
        case 1:drawXByLocation(0,1);break;
        case 2:drawXByLocation(0,2);break;
        case 3:drawXByLocation(1,0);break;
        case 4:drawXByLocation(1,1);break;
        case 5:drawXByLocation(1,2);break;
        case 6:drawXByLocation(2,0);break;
        case 7:drawXByLocation(2,1);break;
        case 8:drawXByLocation(2,2);break;
    }
}

/*function sleep(numberMillis) //��ͣ
{
    var now = new Date();
    var exitTime = now.getTime() + numberMillis;
    while (true) {
        now = new Date();
        if (now.getTime() > exitTime)
            return;
    }
}*/
function drawByArr()//���ݽ�����黭ͼ
{
    var arr = new Array();
    var text = document.getElementById("TextBox4").value;
    arr = text.split(',');
    alert(arr);
    for(i=0;i<9;i++)
    {
        if(arr[i]==1)
        {
            drawRoundByArr(i);
        }
        else if(arr[i]==-1)
        {
            drawXByArr(i);
        }
    }

}
function MainLoop()
{
    var arr = new Array();
    var str = new Array();
    var text = document.getElementById("result_output").value;
    //alert(text);
    str = text.split('\n');
    //alert(str);
    var count = 0;
    var loop = setInterval(function () {
        arr = str[count].split(',');
        //alert(arr);
        for (i = 0; i < 9; i++) {
            if (arr[i] == 1) {
                drawRoundByArr(i);
            }
            else if (arr[i] == -1) {
                drawXByArr(i);
            }
        }
        count++;
        if(count==str.length-1)
        {
            clearInterval(loop);
            var b = arr.join(" ");
            alert(b);
        }
    },500);
    function test()
    {
        alert('test');
    }

}