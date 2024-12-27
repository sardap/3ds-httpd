<script setup lang="ts">
import BookRank from './BookRank.vue'
import { type BookRankProps } from './BookRank.vue'
import { onMounted, ref, watch } from 'vue'

const books: BookRankProps[] = [
  {
    id: 1,
    title: 'Paul Keating: the big-picture leader',
    author: 'Tony Bramston',
    year: 2016,
    picture: '/books/HNI_0002.jpg',
    completed_date: new Date('2024-09-16'),
    rating: '5 Stars',
  },
  {
    id: 2,
    title: 'Bob Hawke: Demons and Destiny',
    author: 'Tony Bramston',
    year: 2022,
    picture: '/books/HNI_0003.jpg',
    completed_date: new Date('2024-10-18'),
    rating: '5 Stars',
  },
  {
    id: 3,
    title: 'Triumph and Demise The Broken Promise of a Labor Generation: Updated Edition',
    author: 'Paul Kelly',
    year: 2014,
    picture: '/books/HNI_0004.jpg',
    completed_date: new Date('2024-11-04'),
    rating: '5 Stars',
  },
  {
    id: 4,
    title: 'John Curtin: A Life',
    author: 'David Day',
    year: 1999,
    picture: '/books/HNI_0005.jpg',
    completed_date: new Date('2024-11-19'),
    rating: '5 Stars',
  },
  {
    id: 5,
    title: 'The Big Fella: Jack Lang and the Australian Labor Party, 1891–1949',
    author: 'Bede Nairn',
    year: 1986,
    picture: '/books/HNI_0006.jpg',
    completed_date: new Date('2024-12-12'),
    rating: '5 Stars',
  },
]

const booksSorted = ref<BookRankProps[]>([])

type OrderByTypes = 'read-asc' | 'read-desc'

const selectedOrderBy = ref<OrderByTypes>('read-desc')

function orderBy(value: OrderByTypes) {
  switch (value) {
    case 'read-asc':
      booksSorted.value = books.sort(
        (a, b) => a.completed_date.getTime() - b.completed_date.getTime(),
      )
      break
    case 'read-desc':
      booksSorted.value = books.sort(
        (a, b) => b.completed_date.getTime() - a.completed_date.getTime(),
      )
      break
  }
}

watch(selectedOrderBy, (value) => {
  orderBy(value)
})

onMounted(() => {
  orderBy(selectedOrderBy.value)
})
</script>

<template>
  <div>
    <select v-model="selectedOrderBy">
      <option value="read-desc">Latest read</option>
      <option value="read-asc">Oldest read</option>
    </select>
    <BookRank v-for="book in booksSorted" :key="book.title" v-bind="book" />
  </div>
</template>

<style scoped></style>
