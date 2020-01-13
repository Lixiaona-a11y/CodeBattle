<?php
/**
 * Created by PhpStorm.
 * User: psxyz
 * Date: 2016/4/12
 * Time: 17:13
 */
namespace Home\Controller;
class RecordController extends HomeController{
    public function index()//记录表
    {

        $model = M('record');
        $page = new \Think\Page($model->count(),5);
        $list = $model->limit($page->firstRow.','.$page->listRows)->select();
        $page->setConfig('theme','%FIRST% %UP_PAGE% %LINK_PAGE% %DOWN_PAGE% %END% %HEADER%');
        $this->assign('_page',$page->show());
        $this->assign('list',$list);
        $this->display('recordlist');
    }
    public function addRecord($game_id,$player1_id,$player2_id,$result_path)
    {
        $model = M('record');
        $data['game_id'] = $game_id;
        $data['player1_id']=$player1_id;
        $data['player2_id']=$player2_id;
        $data['result_path']=$result_path;
        $data['score']=10;
        $data['time'] = date("Y-m-d h:i:s");
        $model->data($data)->add();
    }
}