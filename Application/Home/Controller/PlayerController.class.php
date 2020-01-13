<?php
/**
 * Created by PhpStorm.
 * User: psxyz
 * Date: 2016/4/12
 * Time: 9:58
 */
namespace Home\Controller;

class PlayerController extends HomeController{
    public function index()//玩家列表
    {
        $game_id = I('get.game_id');
        if($game_id==null)
        {
            $this->assign('game_id','请先选择游戏！');
        }
        else
        {
            $this->assign('game_id',$game_id);
        }
        $model = M('member');
        //$list = $model->field('id,username');
        $list=$model->select();

        $this->assign('list',$list);
        $this->display('playerlist');
    }
    public function details()//玩家详情
    {
        if($_GET)
        {
            $data['uid'] = I('get.id');
            $model = M('member');
            $list = $model->where($data)->select();
            $this->assign('list',$list);
            $this->display('playerdetails');
        }
    }

}