<?php
/**
 * Created by PhpStorm.
 * User: psxyz
 * Date: 2016/4/11
 * Time: 9:53
 */
namespace Home\Controller;

class BattleController extends HomeController{

    public function index(){
        if($_GET)
        {
            $player1_id = I('get.player1_id');
            $game_id = I('get.game_id');
            $this->assign("game_id",$game_id);
            $this->assign("player1_id",$player1_id);
            $model= M('game');
            $data['game_id'] = $game_id;
            $list = $model->where($data)->select();
            $this->assign('list',$list);
//            $this->display('BattlePage_1');
            $this->display("index");
        }

    }
    public function submit()
    {
        $player1_id = I('get.player1_id');//被挑战者ID
        $game_id = I('get.game_id');
        $name=is_login();//uid
        dump($player1_id);
        dump($game_id);
        $record = A('Record');
        $record->addRecord($game_id,$player1_id,is_login(),'path');
        dump("test");
    }

    public function play(){
        //得到用户名和路径
        $player1_id = I('get.player1_id');//被挑战者ID
        $game_id = I('get.game_id');
        $name=is_login()."_".$player1_id;//uid
        $path='Public/Home/file/ticktacktoe/';
        //文件操作
        //$player1_text = $_POST["player1_text"];
        $player2_text = $_POST["code"];
        if(!is_dir($path))
        {
            mkdir($path);
            copy("Public/Home/file/ticktacktoe.cpp",$path.$name."_code.cpp");//复制代码
        }
        //else if(is_dir($path.$name."_code.cpp"))
        else
        {
            //unlink($path.$name."_code.cpp");
            copy("Public/Home/file/ticktacktoe.cpp",$path.$name."_code.cpp");
        }
        //组织参数
        $file_path=$path.$name."_code.cpp";
        $file_exe =$name."_code.exe";
        //$file_result=$path.$name."_result.txt";
        $file_result=$name."_result.txt";

        $code_file=fopen($file_path,'a') or die('文件不存在');
        //fwrite($code_file,$player1_text."\r\n");
        fwrite($code_file,$player2_text);
        fclose($code_file);


        //调用批处理编译、运行文件
        exec('START Public\Home\file\action.bat'." ".$file_path." ".$file_exe." ".$file_result);
        //exec('START Public\Home\file\test.bat');
        //读结果
        if(file_exists($file_result))
        {
            $lines = file($file_result);
            //echo json_encode($lines);
            //TODO:添加记录
            $record = A('Record');
            $record->addRecord($game_id,$player1_id,is_login(),$file_result);

            $this->assign('result',$lines);
            $this->display('result');
        }
        else
        {
            $this->error();
        }

        //删除中间文件
        unlink($name."_code.exe");
        unlink($name."_code.obj");
        copy($name."_result.txt","Public/Home/file/ticktacktoe/".$name."_result.txt");
        unlink($name."_result.txt");

    }
}