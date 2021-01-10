package main

import "C"

import (
	"math/rand"
	"encoding/json"
	"io/ioutil"
)

type Life struct {
	Data      []bool
	newData   []bool
	dataSize  int
	SIZE      int
	N         int
	B         map[int]bool
	S         map[int]bool
}

var LIFE Life
var RENDER_SIZE int
var COORD int

func randBool() bool {
	return rand.Float32() < 0.5
}

func intPow(a int, b int) int {
	answer := 1
	for i := 1; i <= b; i++ {
		answer *= a
	}
	return answer
}
func (life *Life) Setup(b []int, s []int, random bool) {
    life.B = make(map[int]bool)
    life.S = make(map[int]bool)
    for _, i := range b {
        life.B[i] = true
    }
    for _, i := range s {
        life.S[i] = true
    }
    life.dataSize = intPow(life.SIZE, life.N)
    life.Data = make([]bool, life.dataSize)
    life.newData = make([]bool, life.dataSize)
    if random {
        for i := 0; i < life.dataSize; i++ {
            life.Data[i] = randBool()
            life.newData[i] = false
        }
    } else {
        for i := 0; i < life.dataSize; i++ {
            life.Data[i] = false
            life.newData[i] = false
        }
    }
}

func (life *Life) inWorld(index int) bool {
	return (index < len(life.Data) && index >= 0)
}

func (life *Life) getCell(index int) bool {
	if !life.inWorld(index) {
		return false
	}
	return life.Data[index]
}

func (life *Life) applyRules(index int) bool {
    cell := life.getCell(index)
    if cell {
        return life.B[life.countNeighbours(index)]
    }
    return life.S[life.countNeighbours(index)]
}

func (life *Life) countNeighbours(index int) int {
	coords := []int{index}
	countN := 0
	for i := 0; i < life.N; i++ {
		step := intPow(life.SIZE, i)
		new_coords := []int{index}
		for _, a := range coords {
			left := a - step
			right := a + step
			if life.inWorld(left) {
				if life.getCell(left) {
					countN++
				}
				new_coords = append(new_coords, left)
			}
			if life.inWorld(right) {
				if life.getCell(right) {
					countN++
				}
				new_coords = append(new_coords, right)
			}
		}
		coords = append(coords, new_coords...)
	}
	return countN
}

func (life *Life) NextGeneration() {
	for i := range life.Data {
	    life.newData[i] = life.applyRules(i)
	}
	life.Data, life.newData = life.newData, life.Data
}

func (life *Life) saveData(fileName string) error {
    file, _ := json.MarshalIndent(life, "", " ")
    _ = ioutil.WriteFile(fileName, file, 0644)
    return nil

}
//export Setup
func Setup(size int, n int, b []int, s[]int, random bool) {
    LIFE := Life{
        SIZE: 32,
        N: 2,
    }
    LIFE.Setup(b, s, random)
    if LIFE.N == 2 {
        RENDER_SIZE = LIFE.SIZE * LIFE.SIZE
    } else {
        RENDER_SIZE = LIFE.SIZE * LIFE.SIZE * LIFE.SIZE
    }
}

//export NextGen
func NextGen() {
    LIFE.NextGeneration()
}

//export SetCoord
func SetCoord(coord int) {
    COORD = coord
}

//export GetRenderData
func GetRenderData() []bool {
    return LIFE.Data[COORD:COORD+RENDER_SIZE]
}

//export CheckCell
func CheckCell(index int) bool {
    return LIFE.getCell(index)
}

func main() {

}
