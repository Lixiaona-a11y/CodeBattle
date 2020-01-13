<?php
/**
 * Created by PhpStorm.
 * User: psxyz
 * Date: 2016/4/12
 * Time: 17:05
 */
namespace Home\Controller;
class GameController extends HomeController{
    public function index()
    {
        //游戏列表
        $model = M('game');
        $list = $model->select();
        $this->assign('list',$list);
        $this->display('gamelist');
    }

}