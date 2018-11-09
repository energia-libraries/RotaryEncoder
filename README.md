# `RotaryEncoder`






## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
[`public  RotaryEncoder(uint16_t pinA,uint16_t pinB)`](#class_rotary_encoder_1a73e038d4ff203123f347ad9e8ba46ba3) | Instantiate the [RotaryEncoder](#class_rotary_encoder) library.
[`public void begin(void(*)(void) callback)`](#class_rotary_encoder_1a616f995ed5c4613822dcc04e79bfde61) | Start the encoder library.
[`public uint8_t handle_encoder()`](#class_rotary_encoder_1a90ed65d8dfc118011001763a152b0584) | Callback to be called from the user specified callback in [begin()](#class_rotary_encoder_1a616f995ed5c4613822dcc04e79bfde61).

## Members


### <a name="class_rotary_encoder_1a73e038d4ff203123f347ad9e8ba46ba3"></a>`public  RotaryEncoder(uint16_t pinA,uint16_t pinB)`

Instantiate the [RotaryEncoder](#class_rotary_encoder) library.

#### Parameters
* `pinA` The pin number to which pin A of the rotary encoder is connected to. 


* `pinB` The pin number to which pin B of the rotary encoder is connected to.

### <a name="class_rotary_encoder_1a616f995ed5c4613822dcc04e79bfde61"></a>`public void begin(void(*)(void) callback)`

Start the encoder library.

#### Parameters
* `callback` A callback to when an interrupt occurs on either pin A or B. This function has to call handle_encoder on the [RotaryEncoder](#class_rotary_encoder) instance. 
```cpp
void myRotaryEncoderCallback()
{
    uint8_t state = myRotaryEncoder.handle_encoder();
    swith(state) {
        case DIRECTION_NONE:
            break;
        case DIRECTION_CCW:
            count--;
            break;
        case DIRECTION_CW:
            count++;
        default:
            break;
    }
}
```

### <a name="class_rotary_encoder_1a90ed65d8dfc118011001763a152b0584"></a>`public uint8_t handle_encoder()`

Callback to be called from the user specified callback in [begin()](#class_rotary_encoder_1a616f995ed5c4613822dcc04e79bfde61).

This function must be called from supplied user callback function specified in.


#### Returns
The state of the encoder.

* `DIRECTION_NONE` if the encoder is stationary.


* `DIRECTION_CCW` if the encoder was turned counter clockwise.


* `DIRECTION_CW` if the encoder was turned clockwise.


