package com.inu.sandwich.sinkhole.Utils;

import android.graphics.Point;

/**
 * Created by 0xFF00FF00 on 2016-05-16.
 */
public class PersonData {
    public String Name;
    public int hp;
    public boolean order;
    public Point pos;
    public Point order_pos;

    public PersonData(int _hp,boolean _order, Point _pos, Point _order_pos,String _name){
        hp = _hp;
        order = _order;
        pos = _pos;
        order_pos = _order_pos;
        Name = _name;
    }
}
